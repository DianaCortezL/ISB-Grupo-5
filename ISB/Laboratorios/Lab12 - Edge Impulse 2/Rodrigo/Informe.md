# **LABORATORIO 12: IMPULSE DESIGN WITH EDGE IMPULSE**
Nombre: Rodrigo Italo Llachua Inocente\
Código: 74285456\
Link del proyecto de Edge Impulse: https://studio.edgeimpulse.com/public/560551/live

## **Objetivo** 
Clasificar los datos correspondientes a las señales ECG mediante un Impulse en la interfaz de Edge Impulse.

## **Metodología** 
**1. Creación del Impulse**\
En la sección de "Impulse Design" se accede a la opción de "Create Impulse" donde usaremos un "Processing Box" de Spectral Analysis y un "Learning Block" de Classification.


**2. Configuración de Spectral Features**\
Dejaremos por defecto los parámetros asignados al bloque "Spectral features" y procederemos la apartado "Create features" donde inicializaremos el proceso de creación de las carácterísticas de nuestra señal.

**3. Clasificación de data**\
Habiendo definido las carácterísticas de nuestra data, procederemos a la configuración de la herramienta "Classifier" y su posterior entrenamiento. En la siguiente imagen es posible apreciar la configuración del "Classifier".


Con estos parámetros se obtuvo la siguiente matriz de confusión de los datos.
