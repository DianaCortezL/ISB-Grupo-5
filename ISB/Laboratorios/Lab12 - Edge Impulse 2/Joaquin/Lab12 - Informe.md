# **LABORATORIO 12: EDGE IMPULSE  - IMPULSE DESIGN**
Nombre: Joaquín Miguel Díaz Lara\
Código: 73707854\
Link del proyecto de Edge Impulse: https://studio.edgeimpulse.com/public/560046/live  

## **Metodología** 
El proceso de creación de un impulse design en Edge Impulse implica varios pasos clave que permiten desarrollar un modelo eficiente para tareas de clasificación basadas en datos de sensores. A continuación, se describe la metodología para implementar este diseño, incluyendo las etapas de creación del impulso, extracción de características espectrales, configuración del clasificador y reentrenamiento del modelo:

**1. Creación del Impulse**\
El primer paso en la plataforma Edge Impulse consiste en definir la estructura básica del impulse, que es la secuencia de operaciones que transforma los datos en una predicción. Se modificó el window size, el window increase y se añadió un processing block de Spectral Analyssis y un learning block de Classification. 

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/d960c3c26e7dd5ecaafd6162ae07024401214b5b/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Joaquin/Imagenes/Create%20Impulse.png width="600" height="300"></p>
<div align="center">Figura 2: Create impulse </i></div>
</p>

**2. Spectral Features**\
Una vez creado el impulso, el siguiente paso es configurar el bloque de procesamiento para calcular las características espectrales. Esto es particularmente útil cuando se trabaja con datos de señales, como audio o vibraciones. Se ajustaron los parámetros de FFT length y se activó el log of spectrum y Overlap FFT frames. Se realizó una previsualización para verificar que las características generadas capturan correctamente las propiedades clave de los datos.

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/d960c3c26e7dd5ecaafd6162ae07024401214b5b/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Joaquin/Imagenes/Par%C3%A1metros.png width="600" height="300"></p>
<div align="center">Figura 3: Spectral features </i></div>
</p>

**3.Classifier**\
En este paso, el bloque de aprendizaje automático se configura para entrenar un clasificador que pueda distinguir entre las diferentes clases de los datos: EJERCICIO, POST RESPIRACIÓN, REPOSO, RESPIRACIÓN Y SIMULADOR.

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/d960c3c26e7dd5ecaafd6162ae07024401214b5b/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Joaquin/Imagenes/Generate%20features.png width="600" height="300"></p>
<div align="center">Figura 4: Parámetros del Classifier </i></div>
</p>

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/d960c3c26e7dd5ecaafd6162ae07024401214b5b/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Joaquin/Imagenes/Neural%20Netwok%20Settings.png width="600" height="300"></p>
<div align="center">Figura 4: Generate features </i></div>
</p>

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/d960c3c26e7dd5ecaafd6162ae07024401214b5b/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Joaquin/Imagenes/Neural%20Netwok%20Settings.png width="600" height="300"></p>
<div align="center">Figura 5: Resultado </i></div>
</p>

**4.Retrain**\
Tras el entrenamiento inicial, el modelo puede requerir ajustes para mejorar su precisión o robustez. En esta etapa:

Se analizan las métricas del modelo, como la precisión, el recall y la matriz de confusión, para identificar posibles áreas de mejora.
Si el desempeño es insuficiente, se pueden reconfigurar los parámetros del impulse o recolectar más datos para mejorar el balance entre las clases.
Finalmente, el modelo se reentrena utilizando el conjunto optimizado de datos y configuraciones.
Este flujo iterativo garantiza que el diseño del impulse se adapte a las características únicas de los datos y las necesidades del proyecto, logrando un modelo eficiente y listo para implementación en dispositivos de borde (edge devices).




1. Se procedió a crear el proyecto en Edge Impulse
<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/ea53e2bb281935420fe7d062eae1931f878dbb76/ISB/Laboratorios/Lab11%20-%20Edge%20Impulse/Joaquin/Imagenes/Img2.png width="600" height="300"></p>
<div align="center">Figura 2: proyecto creado en Edge Impulse </i></div>
</p>

2. Se realizó la configuración de CSV WIZARD
```json
{
    "version": 1,
    "fileName": "reposoD1.csv",
    "created": 1731794829040,
    "delimiter": ";",
    "skipFirstLines": 0,
    "fixedHeader": [
        "Unnamed 1",
        "Unnamed 2"
    ],
    "spec": {
        "type": "timeseries-row",
        "valueColumns": [
            "Unnamed 2"
        ],
        "timestamp": {
            "type": "fixed-frequency",
            "frequency": 1000
        },
        "limitSampleLengthMs": 20000
    }
}
```
## **Subida de datos a Edge Impulse** 
‌Luego de haber realizado la configuración del CSV WIZARD, se procedió a subir los archivos. Para esto, se agruparon los archivos en 5 etiqutas: EJERCICIO, POSTRESPIRACION, REPOSO, RESPIRACION y SIMULADOR. En la Fig. 3 se observa la clasificación de las señales en base a la actividad realizada.

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/19712214149414ae42c598dc2076d3ab74b77ebf/ISB/Laboratorios/Lab11%20-%20Edge%20Impulse/Joaquin/Imagenes/img3.png width="600" height="500"></p>
<div align="center">Figura 3: Dataset filter</i></div>
</p>

Se realizaron movimientos de los datos entre Training y Set para obtener un mejor Dataset train / test split ratio. Finalmente, el data set que se generó se observa en la Fig. 4. Observamos que se obtuvo un ratio de 71%/29% lo cual es un modelo adecuado y preciso. 

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/cabe4950d5a5b0086a2a01962b1a039bde012879/ISB/Laboratorios/Lab11%20-%20Edge%20Impulse/Joaquin/Imagenes/img4.png width="700" height="300"></p>
<div align="center">Figura 4: Dataset final</i></div>
</p>

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/dbcc927561f270816e193ebfb0772264eab484d2/ISB/Laboratorios/Lab11%20-%20Edge%20Impulse/Joaquin/Imagenes/img5.png width="700" height="500"></p>
<div align="center">Figura 5: Dataset train / test split ratio</i></div>
</p>
