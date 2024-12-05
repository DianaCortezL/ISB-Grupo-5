# **LABORATORIO 14: EDGE IMPULSE - ATOM MATRIX**
Nombres: Rodrigo Llacchua Inocente y Joaquín Díaz Lara (73707854)\
Link del proyecto de Edge Impulse:

## **Metodología** 
Para este informe de laboratorio, se utilizó el acelerómetro integrado en el ATOM Matrix como dispositivo principal para la adquisición de datos relacionados con movimientos simples. Se empleó un código desarrollado en Arduino para la configuración del dispositivo y la recolección de datos en tiempo real, los cuales fueron procesados posteriormente con la plataforma Edge Impulse para entrenar un modelo de predicción de movimientos.

El procedimiento comenzó con la programación del ATOM Matrix utilizando el entorno de desarrollo Arduino. El código incluyó configuraciones específicas para acceder a los datos del acelerómetro, habilitando la lectura de los valores en los ejes X, Y y Z. Estos valores fueron capturados a una frecuencia constante, permitiendo registrar patrones precisos de los movimientos realizados.

Se definieron cuatro movimientos específicos que serían la base para el entrenamiento del modelo: movimiento1, movimiento 2, movimiento 3, y movimiento 4. Cada movimiento fue ejecutado por diferentes personas y tuvieron una duración de 10 segundos.
- Movimiento 1: Arriabajo, mover el ATOM de arriba a abajo (en el eje y)
- Movimiento 2: Laditos, mover el ATOM de izquierda a derecha
- Movimiento 3: Circulito, hacer círculos con el ATOM
- Movimiento 4: Profundito, mover el ATOM en el eje z

Los datos obtenidos del acelerómetro fueron enviados en tiempo real a una computadora. Una vez recopilados, se procesaron en un formato compatible con Edge Impulse, asegurando que cada conjunto de datos estuviera etiquetado correctamente de acuerdo con el tipo de movimiento correspondiente. En la plataforma Edge Impulse, se utilizaron estos datos para entrenar un modelo de aprendizaje automático. Una vez finalizado el entrenamiento, se evaluó el modelo utilizando un conjunto de datos nuevo del celular.

Finalmente, se validó el sistema mediante pruebas en las que se replicaron los movimientos originales y se compararon las predicciones del modelo con los movimientos realizados. Este enfoque integró el uso del ATOM Matrix como herramienta de adquisición de datos y la plataforma Edge Impulse para el desarrollo de modelos predictivos.

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/c6227ed841c5991c00b529a5d2c5a4671ece2fbf/ISB/Laboratorios/Lab14/ATOM.jpeg width="400" height="250"></p>
<div align="center">Figura 1: ATOM Matrix</i></div>
</p>

**1. Código en Arduino**
```
#include "M5Atom.h"

void setup(){
  M5.begin(true, false, true);
  M5.IMU.Init();
}

int16_t x,y,z;

void loop(){
  M5.IMU.getAccelAdc(&x,&y,&z);
  Serial.printf("%d %d %d\n",x ,y,z);
  delay(100);
}
```

**2. Edge impulse**\
El primer paso en la plataforma Edge Impulse consiste en definir la estructura básica del impulse, que es la secuencia de operaciones que transforma los datos en una predicción. Se modificó el window size, el window increase y se añadió un processing block de Spectral Analyssis y un learning block de Classification. 

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/cb3a1a1ada1f5b65ea66f3fa798538d5c58dbd46/ISB/Laboratorios/Lab14/Dataset.jpg width="600" height="350"></p>
<div align="center">Figura 2: Dataset </i></div>
</p>

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/cb3a1a1ada1f5b65ea66f3fa798538d5c58dbd46/ISB/Laboratorios/Lab14/Training%20settings.jpg width="600" height="600"></p>
<div align="center">Figura 3: Training settings </i></div>
</p>

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/cb3a1a1ada1f5b65ea66f3fa798538d5c58dbd46/ISB/Laboratorios/Lab14/Results.jpg width="600" height="600"></p>
<div align="center">Figura 4: Results y accuaracy</i></div>
</p>

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/cb3a1a1ada1f5b65ea66f3fa798538d5c58dbd46/ISB/Laboratorios/Lab14/Data%20explorer.jpg
 width="600" height="300"></p>
<div align="center">Figura 5: Data explorer</i></div>
</p>

**3. Resultados**
Para los resultados se usó un celular y el giroscopio del mismo. Se hicieron los mismos resultados y estos se muestran en la Figura 6.

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/077ee02525bb7b5d9f46375754769e5b143e0831/ISB/Laboratorios/Lab14/Resultados.jpg width="600" height="900"></p>
<div align="center">Figura 6: Resultados usando un celular</i></div>
</p>
