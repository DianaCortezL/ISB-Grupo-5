# **LABORATORIO 12: IMPULSE DESIGN WITH EDGE IMPULSE**
Nombre: Rodrigo Italo Llachua Inocente\
Código: 74285456\
Link del proyecto de Edge Impulse: https://studio.edgeimpulse.com/public/560551/live

## **Objetivo** 
Clasificar los datos correspondientes a las señales ECG mediante un Impulse en la interfaz de Edge Impulse.

## **Metodología** 
**1. Creación del Impulse**\
En la sección de "Impulse Design" se accede a la opción de "Create Impulse" donde usaremos un "Processing Box" de Spectral Analysis y un "Learning Block" de Classification.
<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/9034d0ed7033200bcc0e612e75ac7f471185245d/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Rodrigo/Imagenes/createimpulse.JPG width="600" height="300"></p>
<div align="center">Figura 1: Creación de Impulse </i></div>
</p>


**2. Configuración de Spectral Features**\
Dejaremos por defecto los parámetros asignados al bloque "Spectral features" y procederemos la apartado "Create features" donde inicializaremos el proceso de creación de las carácterísticas de nuestra señal.

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/9034d0ed7033200bcc0e612e75ac7f471185245d/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Rodrigo/Imagenes/spectral.JPG width="600" height="500"></p>
<div align="center">Figura 2: Carácterísticas generadas </i></div>
</p>

**3. Clasificación de data**\
Habiendo definido las carácterísticas de nuestra data, procederemos a la configuración de la herramienta "Classifier" y su posterior entrenamiento. En la siguiente imagen es posible apreciar la configuración del "Classifier".

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/9034d0ed7033200bcc0e612e75ac7f471185245d/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Rodrigo/Imagenes/config.JPG width="600" height="500"></p>
<div align="center">Figura 3: Configuración de Classifier </i></div>
</p>
Con estos parámetros se obtuvo la siguiente matriz de confusión de los datos.
<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/9034d0ed7033200bcc0e612e75ac7f471185245d/ISB/Laboratorios/Lab12%20-%20Edge%20Impulse%202/Rodrigo/Imagenes/matriz.JPG width="600" height="300"></p>
<div align="center">Figura 4: Matriz de confusión y porcentaje de precisión </i></div>
</p>

