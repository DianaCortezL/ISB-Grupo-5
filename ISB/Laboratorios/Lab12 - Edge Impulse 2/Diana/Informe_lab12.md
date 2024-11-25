# **LABORATORIO 12: IMPULSE DESIGN WITH EDGE IMPULSE**
Nombre: Diana Isabel Cortez Lopez\
Código: 71727300\
Link del proyecto de Edge Impulse: https://studio.edgeimpulse.com/public/560552/live

## **Objetivo** 
Generar un impulse con la interfaz Edge Impulse usando la data ingresada en el laboratorio N°11.

## **Metodología** 
**1. Creación del Impulse**\
En la barra de selección de la izquierda seleccionar "Create Impulse" usando la data del proyecto donde se subieron los csv. En "Add processing block" seleccionar "Spectral Analysis" y en "Add Learning Block" seleccionar "Classification".
<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/c5969dee18614422bbff7058a8788003cba431ef/ISB/Laboratorios/Lab11%20-%20Edge%20Impulse/Diana/Imagenes/Datos_edge_impulse.png width="600" height="300"></p>
<div align="center">Figura 1: Edge Impulse Proyect </i></div>
</p>

**2. Spectral Features**\
Una vez creado el impulso, el siguiente paso es configurar el bloque de procesamiento para calcular las características espectrales. Esto es particularmente útil cuando se trabaja con datos de señales, como audio o vibraciones. Se ajustaron los parámetros de FFT length y se activó el log of spectrum y Overlap FFT frames. Se realizó una previsualización para verificar que las características generadas capturan correctamente las propiedades clave de los datos.

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/c5969dee18614422bbff7058a8788003cba431ef/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Diana/Imagenes/spectral_features.png width="600" height="300"></p>
<div align="center">Figura 2: Spectral features (parameters) </i></div>
</p>

**3.Classifier**\
En este paso, el bloque de aprendizaje automático se configura para entrenar un clasificador que pueda distinguir entre las diferentes clases de los datos: EJERCICIO, POST RESPIRACIÓN, REPOSO, RESPIRACIÓN Y SIMULADOR.

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/b69ac66a1f2ed190e8004b53470656f602a63f17/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Diana/Imagenes/settings.png width="600" height="300"></p>
<div align="center">Figura 3: Neural Network Settingse </i></div>
</p>

Posterior a eso, al lado derecho se deben visualizar la sección "Model" con "Last training performance" aceptable y el "Data Explorer" en la parte inferior.

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/c5969dee18614422bbff7058a8788003cba431ef/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Diana/Imagenes/model.png width="600" height="500"></p>
<div align="center">Figura 4: Model: Last Training Performance </i></div>
</p>

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/c5969dee18614422bbff7058a8788003cba431ef/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Diana/Imagenes/data_explorer.png width="600" height="500"></p>
<div align="center">Figura 4: Model: Data explorer</i></div>
</p>

## **Resultados** 
Se desarrolló  con exito el modelo, el cual alcanzó un 79.5% de accuracy en la etapa de model testing, lo que indica un buen desempeño en la clasificación de los datos. Aun así, es recomendable aumentar el tiempo acumulado de datos a almenos 2h, según las indicaciones dadas en clase para mayor fiabilidad.
