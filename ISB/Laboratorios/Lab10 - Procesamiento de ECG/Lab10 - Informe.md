# **LABORATORIO 9: PROCESAMIENTO DE SEÑAL EMG**
# **Tabla de contenidos**

1. [Introducción](#id1)
2. [Objetivos](#id2)
3. [Materiales y equipos](#id3)
4. [Métodología](#id4)
5. [Resultados](#id5)
6. [Conclusiones](#id6)
7. [Referencias bibliográficas](#id7)

## **Introducción** <a name="id1"></a>
El procesamiento de señales electromiográficas (EMG) es fundamental en el análisis de la actividad muscular, ya que permite interpretar las señales eléctricas generadas durante la contracción muscular. Estas señales, capturadas mediante electrodos colocados sobre la piel o insertados en el músculo, contienen información clave sobre el estado y el comportamiento de los músculos, siendo ampliamente utilizadas en aplicaciones como la rehabilitación física, el control de prótesis, y la investigación de la fatiga muscular. El procesamiento de las señales EMG implica varias etapas, entre las cuales se incluyen la eliminación de ruido, la segmentación y la extracción de características. El objetivo de procesar y segmentar la señal EMG es adaptarla para su posterior análisis, eliminando el ruido que podría llevar a interpretaciones erróneas.

Una de las principales dificultades en el procesamiento de señales EMG es la presencia de ruido, el cual puede ser generado por diversas fuentes, como el movimiento del sujeto, la actividad cardíaca y las interferencias eléctricas. El uso de filtros es uno de los métodos más efectivos para reducir el ruido de una señal, mejorando su fidelidad. Entre los filtros comúnmente utilizados están los filtros IR y FIR, que ayudan a atenuar frecuencias no deseadas. Además, el uso de métodos basados en wavelets permite descomponer la señal en diferentes niveles de frecuencia, proporcionando una herramienta poderosa para el análisis y filtrado de señales EMG en presencia de ruido de múltiples frecuencias.

La segmentación de la señal es otra etapa crítica, en la cual la señal EMG se divide en intervalos específicos para su análisis. Esto permite identificar patrones de activación muscular en determinados periodos de tiempo, lo cual es esencial en estudios que requieren análisis en tiempo real o que buscan correlacionar actividades musculares con eventos específicos, como en el análisis de la marcha o la detección de movimientos. La longitud de la ventana determina la cantidad de información que se utiliza para la extracción y la clasificación: más datos producirán mejores resultados a costa de aumentar el tiempo de procesamiento del clasificador. Por ejemplo, Englehart et al. obtuvo los mejores resultados para un tiempo de ventana igual a 32 milisegundos. Por otro lado, Phinyomark eta al. determinó que longitudes de segmento entre 125 a 500 ms aumenta significativamente la precisión de la clasificación al reducir el sesgo y la varianza en las característicad calculadas [2].

Finalmente, la extracción de características en la señal EMG es esencial para obtener métricas relevantes que describan el comportamiento muscular, clasificar la actividad muscular, detectar patologías o evaluar el rendimiento muscular en diversas condiciones. Las características extraídas podrían clasificarse en dominios de tiempo o frecuencia. Las características del dominio de tiempo representan la energía de una señal EMG. Por otro lado, las características del dominio de frecuencia, además de mostrar el nivel de activación de los músculos, tienen la capacidad de eliminar el ruido de la señal pero tienen un mayor costo computacional. Algunas de las características más importantes del dominio del tiempo son EMG integrada (IEMG), valor absoluto medio (MAV), raíz cuadrada mediana (RMS), integral cuadrada simple (SSI) o longitud de forma de onda (WL). Las características del dominio de frecuencia se utilizan generalmente para el estudio de la fatiga muscular o en el análisis de la unidad motora, siendo no apropiadas para la clasificación de señales EMG. Algunas de las características más importantes del dominio de frecuencia son frecuencia media (MNF), frecuencia mediana (MDF), frecuencia de potencia media (MNP), frecuencia de pico (PKF) o potencia total (TTP) [3]

<p align="justify">
<p align="center"><img src="../../../Otros/Archivos_varios/Lab09_ProcesamientoEMG/Tabla_características.png" width="500" height="550"></p>
<div align="center">Figura 1: Resumen de características y fórmulas de la señal EMG [4]</i></div>
</p>
  
## **Objetivos** <a name="id2"></a>
* Filtrar señales EMG e identificar el mejor filtro
* Extraer y evaluar características importantes de las señales EMG

## **Materiales y equipos** <a name="id3"></a>
<div align="center">
   
|  **Modelo**  | **Descripción** | **Cantidad** |
|:------------:|:---------------:|:------------:|
|       -      |      Laptop     |       1      |
| - |   Python y librerías  |       -      |
| - |   Visual Studio Code  |       -      |
<div align="center"> Tabla 2: Materiales y equipos</i></div>

</div>

## **Metodología** <a name="id4"></a>
Pongan el tipo de wavelet que se uso para filtrar, los paráemtros (NIVELES, ETC). Pongan que se usó los archivos del tríceps, que se segemntaron las señales (miren el código). Pongan los papers (los nombres y qué extrajimos de ellos). También que se usó la libreria biosignalsnotebooks para extraer las características.

## **Resultados TRICEPS** <a name="id5"></a>
1. **Filtrado y segmentación de las señales EMG**
  - **Reposo**
    IMAGEN DE LA SEÑAL SIN FILTRAR Y FILTRADA Y LA SEGMENTACION FILTRA Y SIN FILTRAR
    <div align="center">
   
|  **Señal sin filtrar**  | **Señal filtrada con transformada de Wavelt** |
|:------------:|:---------------:|
|<p align="center"><img src="../../../Otros/Imagenes/Lab9/reposo_raw.png" width="500" height="270"></p>|<p align="center"><img src="../../../Otros/Imagenes/Lab9/reposo_fil.png" width="500" height="270"></p>| 
<div align="center"> Tabla 3: Filtrado de señal EMG del tríceps en reposo</i></div>

</div>  
    
  - **Esfuerzo**
     IMAGEN DE LA SEÑAL SIN FILTRAR Y FILTRADA Y LA SEGMENTACION FILTRA Y SIN FILTRAR
    <div align="center">
   
|  **Señal sin filtrar**  | **Señal filtrada con transformada de Wavelt** |
|:------------:|:---------------:|
|<p align="center"><img src="../../../Otros/Imagenes/Lab9/esfuerzo_raw.png" width="500" height="270"></p>|<p align="center"><img src="../../../Otros/Imagenes/Lab9/esfuerzo_fil.png" width="500" height="270"></p>| 
<div align="center"> Tabla 4: Filtrado de señal EMG del tríceps en esfuerzo</i></div>

</div>  
    
  - **Sobreesfuerzo**
     IMAGEN DE LA SEÑAL SIN FILTRAR Y FILTRADA Y LA SEGMENTACION FILTRA Y SIN FILTRAR
    <div align="center">
   
|  **Señal sin filtrar**  | **Señal filtrada con transformada de Wavelt** |
|:------------:|:---------------:|
|<p align="center"><img src="../../../Otros/Imagenes/Lab9/sobreesfuerzo_raw.png" width="500" height="270"></p>|<p align="center"><img src="../../../Otros/Imagenes/Lab9/sobreesfuerzo_fil.png" width="500" height="270"></p>| 
<div align="center"> Tabla 5: Filtrado de señal EMG del tríceps en sobreesfuerzo</i></div>

</div>  
   
2. **Extracción de características**\
COMPLETEN LA TABLA CON LOS VALORES 
Luego de realizar el filtrado, se relizó la extracción de las características de la señal filtrada por la transformada de Wavelet. Los parámetros y los resultados se aprecian en la Tabla 6

<div align="center">
  
|Parámetro| Señal EMG en reposo | Señal EMG en esfuerzo | Señal EMG en sobreesfuerzo |
|---------|----------|-----|------------------------------|
|EMG Onset Points|[0.2000118]|[ 7.17323674, 8.22227136, 10.58634938, 13.32243968]|[ 0.20000626, 3.64411406, 13.3424176, 21.33466775]|
|EMG Offset Points|[16.7499882]|[ 7.17323674, 8.22227136, 10.58634938, 13.32243968]|[ 1.61805064,  4.90415349, 14.24944599, 23.44973395]|
|Number of Muscular activations|1|4|4|
|Maximun Activation Time|16.550 s|2.661 s|2.115 s|
|Minimun Activation Time|16.550 s|0.131 s|0.907 s|
|Average Activation Time|16.550 s|0.998 s|1.425 s|
|Standard Deviation Time|0.000 s|1.026 s|0.439 s|
|Maximun EMG (mV)|20.206206855861694 mV|134.18479157727978 mV|476.19925506275627 mV|
|Minimun EMG (mV)|-21.793793144138306 mV|-128.81520842272022 mV|-446.80074493724373 mV|
|Average EMG (mV)|-8.461616955915902e-15 mV|3.69400613013403e-15 mV|-2.768423416927518e-15 mV|
|Standard Deviation EMG (mV)|3.359112035641272 mV|8.066803230862357 mV|30.534436237982515 mV|
|Root Mean Square (mV)|3.3591120356412723 mV|8.066803230862357 mV|30.53443623798252 mV|
|Total Power|11.268124124952907|62.41920762636977|961.5932972648554|
|Median Frequency (Hz)|113.28125 Hz|117.1875 Hz|128.90625 Hz|
|Maximun Frequency (Hz)|58.59375 Hz|89.84375 Hz|121.09375 Hz|
|Zero-Crossing|a|a|a|
<div align="center"> Tabla 6: Parámetros extraídos de la señal EMG en reposo, tensión y oposición</i></div>

</div>

## **Resultados BICEPS** <a name="id6"></a>
1. **Filtrado y segmentación de las señales EMG**
  - **Reposo**
    IMAGEN DE LA SEÑAL SIN FILTRAR Y FILTRADA Y LA SEGMENTACION FILTRA Y SIN FILTRAR
    <div align="center">
   
|  **Señal sin filtrar**  | **Señal filtrada con transformada de Wavelt** |
|:------------:|:---------------:|
|<p align="center"><img src="../../../Otros/Imagenes/Lab9/reposo_raw.png" width="500" height="270"></p>|<p align="center"><img src="../../../Otros/Imagenes/Lab9/reposo_fil.png" width="500" height="270"></p>| 
<div align="center"> Tabla 3: Filtrado de señal EMG del tríceps en reposo</i></div>

</div>  
    
  - **Esfuerzo**
     IMAGEN DE LA SEÑAL SIN FILTRAR Y FILTRADA Y LA SEGMENTACION FILTRA Y SIN FILTRAR
    <div align="center">
   
|  **Señal sin filtrar**  | **Señal filtrada con transformada de Wavelt** |
|:------------:|:---------------:|
|<p align="center"><img src="../../../Otros/Imagenes/Lab9/esfuerzo_raw.png" width="500" height="270"></p>|<p align="center"><img src="../../../Otros/Imagenes/Lab9/esfuerzo_fil.png" width="500" height="270"></p>| 
<div align="center"> Tabla 4: Filtrado de señal EMG del tríceps en esfuerzo</i></div>

</div>  
    
  - **Sobreesfuerzo**
     IMAGEN DE LA SEÑAL SIN FILTRAR Y FILTRADA Y LA SEGMENTACION FILTRA Y SIN FILTRAR
    <div align="center">
   
|  **Señal sin filtrar**  | **Señal filtrada con transformada de Wavelt** |
|:------------:|:---------------:|
|<p align="center"><img src="../../../Otros/Imagenes/Lab9/sobreesfuerzo_raw.png" width="500" height="270"></p>|<p align="center"><img src="../../../Otros/Imagenes/Lab9/sobreesfuerzo_fil.png" width="500" height="270"></p>| 
<div align="center"> Tabla 5: Filtrado de señal EMG del tríceps en sobreesfuerzo</i></div>

</div>  
   
2. **Extracción de características**\
COMPLETEN LA TABLA CON LOS VALORES 
Luego de realizar el filtrado, se relizó la extracción de las características de la señal filtrada por la transformada de Wavelet. Los parámetros y los resultados se aprecian en la Tabla 6

<div align="center">
  
|Parámetro| Señal EMG en reposo | Señal EMG en esfuerzo | Señal EMG en sobreesfuerzo |
|---------|----------|-----|------------------------------|
|EMG Onset Points|[0.2000118]|[ 7.17323674, 8.22227136, 10.58634938, 13.32243968]|[ 0.20000626, 3.64411406, 13.3424176, 21.33466775]|
|EMG Offset Points|[16.7499882]|[ 7.17323674, 8.22227136, 10.58634938, 13.32243968]|[ 1.61805064,  4.90415349, 14.24944599, 23.44973395]|
|Number of Muscular activations|1|4|4|
|Maximun Activation Time|16.550 s|2.661 s|2.115 s|
|Minimun Activation Time|16.550 s|0.131 s|0.907 s|
|Average Activation Time|16.550 s|0.998 s|1.425 s|
|Standard Deviation Time|0.000 s|1.026 s|0.439 s|
|Maximun EMG (mV)|20.206206855861694 mV|134.18479157727978 mV|476.19925506275627 mV|
|Minimun EMG (mV)|-21.793793144138306 mV|-128.81520842272022 mV|-446.80074493724373 mV|
|Average EMG (mV)|-8.461616955915902e-15 mV|3.69400613013403e-15 mV|-2.768423416927518e-15 mV|
|Standard Deviation EMG (mV)|3.359112035641272 mV|8.066803230862357 mV|30.534436237982515 mV|
|Root Mean Square (mV)|3.3591120356412723 mV|8.066803230862357 mV|30.53443623798252 mV|
|Total Power|11.268124124952907|62.41920762636977|961.5932972648554|
|Median Frequency (Hz)|113.28125 Hz|117.1875 Hz|128.90625 Hz|
|Maximun Frequency (Hz)|58.59375 Hz|89.84375 Hz|121.09375 Hz|
<div align="center"> Tabla 6: Parámetros extraídos de la señal EMG en reposo, tensión y oposición</i></div>

</div>

## **Discusión**
El procesamiento y análisis de señales electromiográficas (EMG) son fundamentales para interpretar la actividad muscular en diferentes condiciones—reposo, esfuerzo y sobreesfuerzo. En este estudio, utilizamos la transformada Wavelet para filtrar las señales EMG, reduciendo significativamente el ruido y mejorando la claridad de los patrones de activación muscular.

Filtrado y Claridad de la Señal
La transformación Wavelet demostró ser efectiva en la reducción de ruido para todos los tipos de señal (reposo, esfuerzo, sobreesfuerzo), como se observa en las representaciones en el dominio del tiempo antes y después del filtrado. Las señales sin filtrar mostraban altos niveles de ruido, lo cual puede ocultar características importantes como los puntos de inicio y fin de activación muscular. Al aplicar la transformada Wavelet, logramos atenuar el ruido sin perder componentes esenciales de la señal, lo que permite un análisis más preciso de las contracciones musculares y los intervalos de reposo.

Segmentación y Extracción de Características
Después del filtrado, segmentamos las señales y extraímos varias características en el dominio del tiempo, como RMS, MAV, WL y ZC. Cada característica ofrece información sobre aspectos específicos del comportamiento muscular:

Los valores de Raíz Cuadrada Media (RMS) en la condición de sobreesfuerzo mostraron un aumento significativo en comparación con las condiciones de reposo, lo que indica un nivel más alto de activación muscular y uso de energía.
Las métricas de Valor Absoluto Medio (MAV) y Longitud de Onda (WL) aumentaron con los niveles de esfuerzo, reflejando la complejidad e intensidad de la activación muscular durante las fases de esfuerzo y sobreesfuerzo.
Los recuentos de Cruce por Cero (ZC) se mantuvieron relativamente constantes en todas las condiciones, lo que sugiere que los ciclos de activación-desactivación del músculo no variaron significativamente entre el reposo y los estados activos.
Análisis de Actividad Muscular
Las métricas extraídas coinciden con las respuestas fisiológicas esperadas bajo diferentes condiciones de carga. Por ejemplo, los valores de EMG Integrada (IEMG) y Varianza (VAR) son notablemente mayores durante el esfuerzo y el sobreesfuerzo en comparación con el reposo, lo que indica una mayor reclutación muscular y variabilidad en la amplitud de la señal bajo estrés. Estos resultados se correlacionan con el aumento observado en el compromiso de fibras musculares a medida que aumenta la carga de trabajo.

Análisis en el Dominio de Frecuencia
Los parámetros en el dominio de frecuencia, como Frecuencia Mediana y Frecuencia Máxima, fueron notablemente más altos en la condición de sobreesfuerzo. Este desplazamiento de frecuencia coincide con la literatura sobre fatiga muscular, donde la activación muscular bajo esfuerzo prolongado recluta unidades motoras de mayor frecuencia. Esta tendencia apoya la interpretación de un aumento en los niveles de fatiga en la condición de sobreesfuerzo.

### **Archivos** 
- [Documentos (.txt)](https://github.com/DianaCortezL/ISB-Grupo-5/tree/7c6ef550649274b69b6c0ab7dcd442e831e8bcb9/Otros/Archivos_varios/Lab4_EMG)
- [Procesamiento EMG (Reposo)](https://github.com/DianaCortezL/ISB-Grupo-5/blob/6a930f7d20f137c8c6b990800fcf1ac7b113b70a/ISB/Laboratorios/Lab09%20-%20Procesamiento%20de%20EMG/EMG/prueba2/Triceps_reposo.ipynb)
- [Procesamiento EMG (Esfuerzo)](https://github.com/DianaCortezL/ISB-Grupo-5/blob/6a930f7d20f137c8c6b990800fcf1ac7b113b70a/ISB/Laboratorios/Lab09%20-%20Procesamiento%20de%20EMG/EMG/prueba2/Triceps_esfuerzo.ipynb)
- [Procesamiento EMG (Sobreesfuerzo)](https://github.com/DianaCortezL/ISB-Grupo-5/blob/6a930f7d20f137c8c6b990800fcf1ac7b113b70a/ISB/Laboratorios/Lab09%20-%20Procesamiento%20de%20EMG/EMG/prueba2/Triceps_sobreesfuerzo.ipynb)

## **Conclusiones** <a name="id6">
   - Se identificaron correctamente las características en cada señal EMG correspondiente a reposo, esfuerzo y sobreesfuerzo.
   - Se cuantificaron las características y ordenaron en una tabla para una mejor indentifación.
   - Se hizo uso de la transformada Wavelet para la identificación de las características anteriormente mencionadas.

## **Referencias bibliográficas** <a name="id7"></a>
[1] Englehart, K.; Hudgins, B. A Robust, Real-Time Control Scheme for Multifunction Myoelectric Control. IEEE Trans. Biomed. Eng. 2003, 50, 848–854.

[2] A. Phinyomark, F. Quaine, S. Charbonnier, C. Serviere, F. Tarpin-Bernard, and Y. Laurillau, “EMG feature evaluation for improvingmyoelectric pattern recognition robustness,” Expert Systems with ap-plications, vol. 40, no. 12, pp. 4832–4840, 2013
 
[3] del Olmo, Manuel, and Rosario Domingo. “EMG Characterization and Processing in Production Engineering.” Materials, vol. 13, no. 24, 20 Dec. 2020, p. 5815, https://doi.org/10.3390/ma13245815.

[4]Turner, Amber, et al. “Comparing Machine Learning Methods and Feature Extraction Techniques for the EMG Based Decoding of Human Intention.” 2021 43rd Annual International Conference of the IEEE Engineering in Medicine & Biology Society (EMBC), 1 Nov. 2021, https://doi.org/10.1109/embc46164.2021.9630998.
