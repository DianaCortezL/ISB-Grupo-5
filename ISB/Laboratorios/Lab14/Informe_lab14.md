# **LABORATORIO 14: EDGE IMPULSE - ATOM MATRIX**
Nombres: Rodrigo Llacchua Inocente y Joaquín Díaz Lara (73707854)\
Link del proyecto de Edge Impulse:

## **Metodología** 
Para este informe de laboratorio, se utilizó el acelerómetro integrado en el ATOM Matrix como dispositivo principal para la adquisición de datos relacionados con movimientos simples. Se empleó un código desarrollado en Arduino para la configuración del dispositivo y la recolección de datos en tiempo real, los cuales fueron procesados posteriormente con la plataforma Edge Impulse para entrenar un modelo de predicción de movimientos.

El procedimiento comenzó con la programación del ATOM Matrix utilizando el entorno de desarrollo Arduino. El código incluyó configuraciones específicas para acceder a los datos del acelerómetro, habilitando la lectura de los valores en los ejes X, Y y Z. Estos valores fueron capturados a una frecuencia constante, permitiendo registrar patrones precisos de los movimientos realizados.

Se definieron cuatro movimientos específicos que serían la base para el entrenamiento del modelo: movimiento1, movimiento 2, movimiento 3, y movimiento 4. Cada movimiento fue ejecutado por diferentes personas y tuvieron una duración de 10 segundos.
- Movimiento 1: Arriabajo, mover el ATOM de arriba a abajo
- Movimiento 2: Laditos
- Movimiento 3: Circulito
- Movimiento 4: Profundito

Los datos obtenidos del acelerómetro fueron enviados en tiempo real a una computadora. Una vez recopilados, se procesaron en un formato compatible con Edge Impulse, asegurando que cada conjunto de datos estuviera etiquetado correctamente de acuerdo con el tipo de movimiento correspondiente. En la plataforma Edge Impulse, se utilizaron estos datos para entrenar un modelo de aprendizaje automático. Una vez finalizado el entrenamiento, se evaluó el modelo utilizando un conjunto de datos nuevo del celular.

Finalmente, se validó el sistema mediante pruebas en las que se replicaron los movimientos originales y se compararon las predicciones del modelo con los movimientos realizados. Este enfoque integró el uso del ATOM Matrix como herramienta de adquisición de datos y la plataforma Edge Impulse para el desarrollo de modelos predictivos.

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/c6227ed841c5991c00b529a5d2c5a4671ece2fbf/ISB/Laboratorios/Lab14/ATOM.jpeg width="400" height="250"></p>
<div align="center">Figura 1: ATOM Matrix</i></div>
</p>

**1. Código en Arduino**\

**2. Edge impulse**\
El primer paso en la plataforma Edge Impulse consiste en definir la estructura básica del impulse, que es la secuencia de operaciones que transforma los datos en una predicción. Se modificó el window size, el window increase y se añadió un processing block de Spectral Analyssis y un learning block de Classification. 

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/d960c3c26e7dd5ecaafd6162ae07024401214b5b/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Joaquin/Imagenes/Create%20Impulse.png width="600" height="300"></p>
<div align="center">Figura 2: Create impulse </i></div>
</p>

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/d960c3c26e7dd5ecaafd6162ae07024401214b5b/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Joaquin/Imagenes/Par%C3%A1metros.png width="600" height="300"></p>
<div align="center">Figura 3: Spectral features (parameters) </i></div>
</p>

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/d960c3c26e7dd5ecaafd6162ae07024401214b5b/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Joaquin/Imagenes/Generate%20features.png width="600" height="300"></p>
<div align="center">Figura 4: Generate features </i></div>
</p>

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/d960c3c26e7dd5ecaafd6162ae07024401214b5b/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Joaquin/Imagenes/Neural%20Netwok%20Settings.png
 width="600" height="500"></p>
<div align="center">Figura 5: Parámetros del Classifier (Neural Network Settings) </i></div>
</p>

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/8417ddced3b4454b3c1553d262f771786c9c4a44/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Joaquin/Imagenes/Model.png width="600" height="500"></p>
<div align="center">Figura 6: Model </i></div>
</p>

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/8417ddced3b4454b3c1553d262f771786c9c4a44/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Joaquin/Imagenes/Data%20explorer.png width="600" height="500"></p>
<div align="center">Figura 7: Data explorer</i></div>
</p>

**5.Model testing**
<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/0c6cf3831aa3e8aa437927e5d2bc63ffd0f71b1c/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Joaquin/Imagenes/Model%20testing.png width="600" height="700"></p>
<div align="center">Figura 9: Model Testing</i></div>
</p>

El modelo desarrollado alcanzó un 68.31% de accuracy en la etapa de model testing, lo que indica un desempeño moderado pero no óptimo en la clasificación de los datos. Este resultado sugiere que el modelo tiene limitaciones para distinguir correctamente entre las clases objetivo, especialmente en los casos correspondientes a las categorías de postrespiración y respiración, donde se observaron porcentajes elevados de incertidumbre del 68.8% y 75.6%, respectivamente.

Los porcentajes de incertidumbre en estas clases indican que el modelo no está seguro al tomar decisiones para estas categorías. Esto puede deberse a:
- Características similares o superpuestas entre las clases de postrespiración y respiración, lo que dificulta la diferenciación por parte del modelo.
- Datos insuficientes o no representativos en el conjunto de entrenamiento, especialmente para estas clases específicas.
- Configuraciones subóptimas en el bloque de procesamiento o el clasificador del impulse design, como parámetros de características espectrales que no capturan de manera efectiva los patrones relevantes.

Recomendaciones para mejorar el desempeño:
- Ampliar el conjunto de datos: Recolectar más datos para las clases de postrespiración y respiración con mayor variabilidad para capturar mejor sus patrones distintivos.
- Asegurar un balance adecuado entre las clases para evitar sesgos en el modelo.
