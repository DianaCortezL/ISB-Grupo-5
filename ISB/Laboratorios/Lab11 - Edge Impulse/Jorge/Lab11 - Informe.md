# **LABORATORIO 11: DATOS ESTRUCTURADOS / EDGE IMPULSE**
Nombre: Jorge Chavez Echajaya\
Código: 72215542\
Link del proyecto de Edge Impulse: https://studio.edgeimpulse.com/public/558234/live 

## **Metodología** 
Para este laboratorio se use los datos ECG adquiridos por el Bitalino. Posteriormete se usó la plataforma Edge Impulse el cuál se subió los datos adquiridos en formato .csv. Se utilizaron los datos de las tres derivaciones bipolares cuando la persona se ecuentra en:
- estado basal
- manteniendo la respiración
- post respiración
- después de realizar un ejercicio
- simulador prosim

## **Convertir datos .txt a .csv** 
Debido a que la plataforma Edge Impulse no permite cargar archivos en formato .txt, fue necesario convertirlos al formato .csv. Para lograr esto, se implementó un script en MATLAB que automatiza dicho procedimiento. El proceso consistió en leer los datos contenidos en los archivos .txt, seleccionar únicamente las columnas relevantes, y luego guardarlos en formato .csv para su posterior utilización.

El script procesó cada archivo de texto, eliminando información no necesaria, y se centró específicamente en extraer las columnas correspondientes a las muestras y a las amplitudes. A continuación, se muestra el código utilizado en MATLAB:

```python
clear;

% Nombre del archivo a procesar
filename = 'postRespD3.txt';

% Importar los datos del archivo .txt usando tabulación como separador
data = importdata(filename, '\t');

% Seleccionar las columnas de interés (primera y sexta)
datos_guardar = data.data(:, [1, 6]);

% Guardar los datos seleccionados en un archivo .csv
writematrix(datos_guardar, 'datos_postRespD3.csv');
```
![Imagen 1](fotos/image(1).png)

*Figura 1: Código para convertir datos*

## **Adquisición del dataset** 
1. Se procedió a crear el proyecto en Edge Impulse

![Imagen 2](fotos/image(2).png) 
*Figura 2: Proyecto en Edge Impulse*


2. Se realizó la configuración de CSV WIZARD, se configuró seleccionando solo la columna con los valores a traves del tiempo de las tres derivaciones bipolares.

![Imagen 3](fotos/image(3).png)
*Figura 3: CSV Wizard*

![Imagen 4](fotos/image(4).png)
*Figura 4: Configuración del CSV Wizard*

## **Subida de datos a Edge Impulse** 
3. Después de configurar el CSV WIZARD, se llevó a cabo la carga de los archivos. Para ello, estos se organizaron en cinco categorías o capas: EJERCICIO, POSTRESPIRACIÓN, REPOSO, RESPIRACIÓN y SIM. En la Figura 5 se muestra cómo se clasificaron las señales según la actividad realizada.

![Imagen 5](fotos/image(6).png)
*Figura 5: Clasificación de los layers*

4. Se realizó una redistribución de los datos entre Training y Set con el objetivo de lograr un mejor balance en el ratio de división del conjunto de entrenamiento y prueba. Como resultado, el dataset final se puede apreciar en la Figura 6, mostrando un ratio de 72%/28%, lo cual representa un modelo equilibrado y preciso.
![Imagen 6](fotos/image(5).png)
*Figura 6: Data entrenada*


