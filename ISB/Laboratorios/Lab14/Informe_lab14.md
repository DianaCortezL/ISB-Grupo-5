# **LABORATORIO 14: EDGE IMPULSE - ATOM MATRIX**
Nombres: RJoaquín Díaz Lara\
Link del proyecto de Edge Impulse: https://studio.edgeimpulse.com/public/560046/live  

## **Metodología** 
El proceso de creación de un impulse design en Edge Impulse implica varios pasos clave que permiten desarrollar un modelo eficiente para tareas de clasificación basadas en datos de sensores. 

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/73bcec116dde0d132c061c9f8c02eeaefbf6196a/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Joaquin/Imagenes/Dataset.png width="600" height="300"></p>
<div align="center">Figura 1: Dataset</i></div>
</p>

A continuación, se describe la metodología para implementar este diseño, incluyendo las etapas de creación del impulso, extracción de características espectrales, configuración del clasificador y reentrenamiento del modelo:

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
<div align="center">Figura 3: Spectral features (parameters) </i></div>
</p>

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/d960c3c26e7dd5ecaafd6162ae07024401214b5b/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Joaquin/Imagenes/Generate%20features.png width="600" height="300"></p>
<div align="center">Figura 4: Generate features </i></div>
</p>

**3.Classifier**\
En este paso, el bloque de aprendizaje automático se configura para entrenar un clasificador que pueda distinguir entre las diferentes clases de los datos: EJERCICIO, POST RESPIRACIÓN, REPOSO, RESPIRACIÓN Y SIMULADOR.

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

**4.Retrain**\
Tras el entrenamiento inicial, el modelo puede requerir ajustes para mejorar su precisión o robustez. En esta etapa se analizan las métricas del modelo, como la precisión, el recall y la matriz de confusión, para identificar posibles áreas de mejora. Si el desempeño es insuficiente, se pueden reconfigurar los parámetros del impulse o recolectar más datos para mejorar el balance entre las clases. Finalmente, el modelo se reentrena utilizando el conjunto optimizado de datos y configuraciones. Este flujo iterativo garantiza que el diseño del impulse se adapte a las características únicas de los datos y las necesidades del proyecto, logrando un modelo eficiente y listo para implementación en dispositivos de borde (edge devices).

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/73bcec116dde0d132c061c9f8c02eeaefbf6196a/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Joaquin/Imagenes/Retrain.png width="600" height="200"></p>
<div align="center">Figura 8: Retrain</i></div>
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
