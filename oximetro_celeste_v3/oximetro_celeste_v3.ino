
#include "BLEDevice.h"
#include "BluetoothSerial.h"

//**Frecuencia respiratoria
#include <Arduino.h>

// LIBRERIA SHT 1
#include <SHT3x.h>
SHT3x Sensor_FAST;

// LIBRERIA SHT 2
#include <Wire.h>
#include "Adafruit_SHT31.h"
bool enableHeater = false;
uint8_t loopCnt = 0;
Adafruit_SHT31 sht31 = Adafruit_SHT31();
//**************************

// Check if Bluetooth configs are enabled
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Bluetooth Serial object
BluetoothSerial SerialBT;

/*******************************DESVINCULAR****************/
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include"esp_gap_bt_api.h"
#include "esp_err.h"

#define REMOVE_BONDED_DEVICES 1   // <- Set to 0 to view all bonded devices addresses, set to 1 to remove
#define PAIR_MAX_DEVICES 20
uint8_t pairedDeviceBtAddr[PAIR_MAX_DEVICES][6];
char bda_str[18];

bool initBluetooth()
{
  if(!btStart()) {
    Serial.println("Failed to initialize controller");
    return false;
  }
 
  if(esp_bluedroid_init() != ESP_OK) {
    Serial.println("Failed to initialize bluedroid");
    return false;
  }
 
  if(esp_bluedroid_enable() != ESP_OK) {
    Serial.println("Failed to enable bluedroid");
    return false;
  }
  return true;
}

char *bda2str(const uint8_t* bda, char *str, size_t size)
{
  if (bda == NULL || str == NULL || size < 18) {
    return NULL;
  }
  sprintf(str, "%02x:%02x:%02x:%02x:%02x:%02x",
          bda[0], bda[1], bda[2], bda[3], bda[4], bda[5]);
  return str;
}
/************************************************************************/

String message = "";
char incomingChar;

// The remote service we wish to connect to.
static BLEUUID serviceUUID("0000ffb0-0000-1000-8000-00805f9b34fb");
// The characteristic of the remote service we are interested in.
static BLEUUID    charUUID("0000ffb2-0000-1000-8000-00805f9b34fb");

static boolean doConnect = false;
static boolean connected = false;
static boolean doScan = false;
static BLERemoteCharacteristic* pRemoteCharacteristic;
static BLEAdvertisedDevice* myDevice;

int bpm;
int spo2;
//************FACTOR DE CORRECCIÓN************
float factorCorr=3.5;
//************Frecuencia respiratoria************
float v;              // valor actual
float vmax = 0;       // valor anterior
float temp;           // valor de la temperatura
//int state = 15;       //0 for signal going down, 15 for signal going up
int state = 35;
float tempMax;
float tempMaxAcum=0;
float tempMaxProm;
float error = 0.2;    // ayuda a eliminar picos pequeños
//****//
int state2 = 0;       //  estado que sirve para guardar vinicial
float vinicial;       //  guarda el primer valor cuando la señal esta en bajada
float tiempo;
float periodo = 0;
float frecuencia;
int contador = 0;     //  cuenta el numero de datos de frecuencia para luego sacar el promedio
float promfrec = 0;   //  suma todas las frecuencias para luego sacar el promedio
//************************************************
int datastate = 0;    //estado que sirve para iniciar el proceso de medicion


static void notifyCallback(
  BLERemoteCharacteristic* pBLERemoteCharacteristic,
  uint8_t* pData,
  size_t length,
  bool isNotify) {

if (pData[0] == 0xFF && pData[1] == 0xFE && pData[2] == 0xB ){
  spo2 = pData[8];
  bpm = pData[7];
}
}

class MyClientCallback : public BLEClientCallbacks {
    void onConnect(BLEClient* pclient) {
    }

    void onDisconnect(BLEClient* pclient) {
      connected = false;
      Serial.println("onDisconnect");
    }
};

bool connectToServer() {
  Serial.print("Forming a connection to ");
  Serial.println(myDevice->getAddress().toString().c_str());

  BLEClient*  pClient  = BLEDevice::createClient();
  Serial.println(" - Created client");

  pClient->setClientCallbacks(new MyClientCallback());

  // Connect to the remove BLE Server.
  pClient->connect(myDevice);  // if you pass BLEAdvertisedDevice instead of address, it will be recognized type of peer device address (public or private)
  Serial.println(" - Connected to server");

  // Obtain a reference to the service we are after in the remote BLE server.
  BLERemoteService* pRemoteService = pClient->getService(serviceUUID);
  if (pRemoteService == nullptr) {
    Serial.print("Failed to find our service UUID: ");
    Serial.println(serviceUUID.toString().c_str());
    pClient->disconnect();
    return false;
  }
  Serial.println(" - Found our service");


  // Obtain a reference to the characteristic in the service of the remote BLE server.
  pRemoteCharacteristic = pRemoteService->getCharacteristic(charUUID);
  if (pRemoteCharacteristic == nullptr) {
    Serial.print("Failed to find our characteristic UUID: ");
    Serial.println(charUUID.toString().c_str());
    pClient->disconnect();
    return false;
  }
  Serial.println(" - Found our characteristic");

  // Read the value of the characteristic.
  if (pRemoteCharacteristic->canRead()) {
    std::string value = pRemoteCharacteristic->readValue();
    Serial.print("The characteristic value was: ");
    Serial.println(value.c_str());
  }

  if (pRemoteCharacteristic->canNotify())
    pRemoteCharacteristic->registerForNotify(notifyCallback);

  connected = true;
  return true;
}
/**
   Scan for BLE servers and find the first one that advertises the service we are looking for.
*/
class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    /**
        Called for each advertising BLE server.
    */
    void onResult(BLEAdvertisedDevice advertisedDevice) {
      Serial.print("BLE Advertised Device found: ");
      Serial.println(advertisedDevice.toString().c_str());

      // We have found a device, let us now see if it contains the service we are looking for.
      if (advertisedDevice.haveServiceUUID() && advertisedDevice.isAdvertisingService(serviceUUID)) {

        BLEDevice::getScan()->stop();
        myDevice = new BLEAdvertisedDevice(advertisedDevice);
        doConnect = true;
        doScan = true;

      } // Found our server
    } // onResult
}; // MyAdvertisedDeviceCallbacks


void setup() {

  Serial.begin(115200);
  
  Serial.println("Starting Arduino BLE Client application...");
  BLEDevice::init("");
  
  SerialBT.begin("ESP32");
  Serial.println("The device started, now you can pair it with bluetooth!");
  
//**************
  initBluetooth();
  Serial.print("ESP32 bluetooth address: "); Serial.println(bda2str(esp_bt_dev_get_address(), bda_str, 18));
  // Get the numbers of bonded/paired devices in the BT module
  int count = esp_bt_gap_get_bond_device_num();
  if(!count) {
    Serial.println("No bonded device found.");
  } else {
    Serial.print("Bonded device count: "); Serial.println(count);
    if(PAIR_MAX_DEVICES < count) {
      count = PAIR_MAX_DEVICES; 
      Serial.print("Reset bonded device count: "); Serial.println(count);
    }
    esp_err_t tError =  esp_bt_gap_get_bond_device_list(&count, pairedDeviceBtAddr);
    if(ESP_OK == tError) {
      for(int i = 0; i < count; i++) {
        Serial.print("Found bonded device # "); Serial.print(i); Serial.print(" -> ");
        Serial.println(bda2str(pairedDeviceBtAddr[i], bda_str, 18));     
        if(REMOVE_BONDED_DEVICES) {
          esp_err_t tError = esp_bt_gap_remove_bond_device(pairedDeviceBtAddr[i]);
          if(ESP_OK == tError) {
            Serial.print("Removed bonded device # "); 
          } else {
            Serial.print("Failed to remove bonded device # ");
          }
          Serial.println(i);
        }
      }        
    }
  }

//************
  Sensor_FAST.SetUpdateInterval(100); //La data se actualizará 10 veces por segundo
  Sensor_FAST.Begin();
//************
  
  // Retrieve a Scanner and set the callback we want to use to be informed when we
  // have detected a new device.  Specify that we want active scanning and start the
  // scan to run for 5 seconds.
  BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setInterval(1349);
  pBLEScan->setWindow(449);
  pBLEScan->setActiveScan(true);
  pBLEScan->start(5, false);

} 


void loop() {

  // If the flag "doConnect" is true then we have scanned for and found the desired
  // BLE Server with which we wish to connect.  Now we connect to it.  Once we are
  // connected we set the connected flag to be true.
  if (doConnect == true) {
    if (connectToServer()) {
      Serial.println("We are now connected to the BLE Server.");
      SerialBT.println("We are now connected to the BLE Server.");
    } else {
      Serial.println("We have failed to connect to the server; there is nothin more we will do.");
    }
    doConnect = false;
  }

  // If we are connected to a peer BLE Server, update the characteristic each time we are reached
  // with the current time since boot.
  if (connected) {
    String newValue = "Time since boot: " + String(millis() / 1000);
//    Serial.println("Setting new characteristic value to \"" + newValue + "\"");

    // Set the characteristic's value to be the array of bytes that is actually a string.
    pRemoteCharacteristic->writeValue(newValue.c_str(), newValue.length());
  } else if (doScan) {
    BLEDevice::getScan()->start(0);  // this is just eample to start scan after disconnect, most likely there is better way to do it in arduino
  }

if (datastate == 1){
  FrecResp();
}

// Serial.print(" bpm ");
//   Serial.print(bpm);
//   Serial.print(" spo2 ");
//   Serial.println(spo2);

//Serial Bluetooth

if (SerialBT.available()){
    char incomingChar = SerialBT.read();
    if (incomingChar != '\n'){
      message += String(incomingChar);
    }
    else{
      message = "";
    }
    Serial.write(incomingChar);  
  }
  // Check received message and control output accordingly
  if (message =="inicio"){
    tempMaxAcum=0;
    if (spo2 == 0 || bpm == 0){
      SerialBT.println("Encender el oximetro antes que el dispositivo");
    }
    /*else if (periodo == 0 || periodo > 10){
      SerialBT.println("Acercar el dispotivo");
    }*/
    else{
      datastate = 1; 
      SerialBT.println("Iniciar conteo");
     }
  }
if (message =="final"){
  datastate = 0;
  frecuencia = promfrec/contador;
      SerialBT.println("Sp"+String(spo2)+"|"+String(bpm)+"|"+String(contador+1)+"|"+String(tempMaxProm)); 
      contador = 0;
      frecuencia = 0;
      promfrec = 0;
}
  
  delay(100); // Delay a second between loops.
}


//********************************************************
void FrecResp() {
  //leer señal
  Sensor_FAST.UpdateData();
//  v = Sensor_FAST.GetTemperature(SHT3x::Far)-75;
    v = ((Sensor_FAST.GetTemperature(SHT3x::Far)-32)* 5/9);//valor de correccion temp int ext+4.5
//  v= sht31.readTemperature();
  temp = (Sensor_FAST.GetTemperature(SHT3x::Far)-32)* 5/9;
//  temp = sht31.readTemperature();
  
  //Flanco de subida
  if(v>vmax && state == 35){
    vmax=v;
    if(vmax-vinicial>error){
      vinicial= vmax;
    }
  }

  //Flanco de bajada
  if(v<vmax){

    if (state == 35 && state2 ==0){
      //empieza la bajada y guardamos el primer dato de bajada
    vinicial= v;
    state2 = 1;
//    if(tempMax==0){
      tempMax = v;
//    }else{
      tempMaxAcum = tempMaxAcum + tempMax;
      
//    }
    }
    
    if (state == 35 && state2 == 1 && vinicial-v>error){
    state = 30;             //final
    
    
    state2 = 0;
    periodo = (millis()-tiempo)/1000;
    if (periodo <7){                        //al inicio suele mandar datos mayores a 10 si es que
    contador++;                             //se inicio el proceso antes de colocarse bien el dispositivo
    frecuencia = (1/periodo)*60;
    promfrec = promfrec + frecuencia;
    //tempMaxProm = 3.5+tempMaxAcum/(contador+1); // sacar promedio NEW ADD 3.5
    tempMaxProm = factorCorr+tempMaxAcum/(contador+1); // sacar promedio NEW ADD 3.5
    }
    
    }
    
    vmax=v;
  }
  
  if(v>vmax && state == 30){

    vmax=v;
    state = 35;           //inicio
    tiempo = millis();
  }

//si el periodo varia entre mas de 4 seg entre uno y otro, no imprimir valor 

  //SERIAL PLOTTER
  Serial.print(state);
  Serial.print(","); 
  Serial.print(vinicial);
  Serial.print(","); 
  Serial.print(vmax);
  if(tempMax!=0){
     Serial.print(","); 
  Serial.println(tempMax);
  }
//SERIAL MONITOR 
 
  //Serial.print(" TempMax: ");
  //Serial.print(tempMax);
  //Serial.print(" TempMaxAcum: ");
  //Serial.print(tempMaxAcum);
  //Serial.print(" TempMaxProm: ");
  //Serial.print(tempMaxProm);
  //Serial.print(" Vinicial: ");
  //Serial.print(vinicial);
  //Serial.print(" V: ");
  //Serial.print(v); 
  //Serial.print(" conteo: "); 
  //Serial.println(contador);
  //Serial.println("Sp"+String(spo2)+"|"+String(bpm)+"|"+String(contador+1)+"|"+String(tempMaxProm));//añadido
  
  //SERIAL MONITOR 
//   Serial.print(" Periodo:"); 
//   Serial.print(periodo);
//   Serial.print(" seg"); 
//   Serial.print(" Frecuencia:"); 
//   Serial.print(frecuencia);
//   Serial.print(" RPM");
//   Serial.print(" Frecuencia prom:"); 
//   Serial.print(promfrec);
//   Serial.print(" conteo:"); 
//   Serial.println(contador);

}
