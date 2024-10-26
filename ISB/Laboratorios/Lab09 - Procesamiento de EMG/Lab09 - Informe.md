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
El procesamiento de señales electromiográficas (EMG) es fundamental en el análisis de la actividad muscular, ya que permite interpretar las señales eléctricas generadas durante la contracción muscular. Estas señales, capturadas mediante electrodos colocados sobre la piel o insertados en el músculo, contienen información clave sobre el estado y el comportamiento de los músculos, siendo ampliamente utilizadas en aplicaciones como la rehabilitación física, el control de prótesis, y la investigación de la fatiga muscular. El procesamiento de las señales EMG implica varias etapas, entre las cuales se incluyen la eliminación de ruido, la segmentación y la extracción de características.

Una de las principales dificultades en el procesamiento de señales EMG es la presencia de ruido, el cual puede ser generado por diversas fuentes, como el movimiento del sujeto, la actividad cardíaca y las interferencias eléctricas. Para eliminar o reducir el ruido, se emplean técnicas de filtrado que permiten obtener una señal más clara y precisa. Entre los filtros comúnmente utilizados están los filtros IR (Infinite Impulse Response) y FIR (Finite Impulse Response), que ayudan a atenuar frecuencias no deseadas. Además, el uso de métodos basados en wavelets permite descomponer la señal en diferentes niveles de frecuencia, proporcionando una herramienta poderosa para el análisis y filtrado de señales EMG en presencia de ruido de múltiples frecuencias.

La segmentación de la señal es otra etapa crítica, en la cual la señal EMG se divide en intervalos específicos para su análisis. Esto permite identificar patrones de activación muscular en determinados periodos de tiempo, lo cual es esencial en estudios que requieren análisis en tiempo real o que buscan correlacionar actividades musculares con eventos específicos, como en el análisis de la marcha o la detección de movimientos.

Finalmente, la extracción de características en la señal EMG es esencial para obtener métricas relevantes que describan el comportamiento muscular. Esta etapa se centra en derivar parámetros como la amplitud media, la energía de la señal, o la frecuencia media, que son útiles para clasificar la actividad muscular, detectar patologías o evaluar el rendimiento muscular en diversas condiciones. El procesamiento adecuado de las señales EMG permite obtener una representación confiable y detallada de la actividad muscular, mejorando así la precisión y la utilidad de las aplicaciones biomédicas.



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
<div align="center"> Tabla 1: Materiales y equipos</i></div>

</div>

## **Metodología** <a name="id4"></a>


## **Resultados** <a name="id5"></a>

<p align="justify">
<p align="center"><img src="../../../Otros/Archivos_varios/Lab8_Wavelet/ECG1_level.jpg" width="500" height="550"></p>
<div align="center">Figura 1: Niveles de descomposición</i></div>
</p>
  
<div align="center">
   
|  **Señal sin filtrar**  | **Señal filtrada con transformada de Wavelt** |
|:------------:|:---------------:|
|<p align="center"><img src="../../../Otros/Archivos_varios/Lab8_Wavelet/ECG1_raw.jpg" width="500" height="270"></p>|<p align="center"><img src="../../../Otros/Archivos_varios/Lab8_Wavelet/ECG1_wave.jpg" width="500" height="270"></p>| 
<div align="center"> Tabla 2: Filtrado de señal EMG en reposo</i></div>

</div>  

### **Archivos** 
- [Documentos (.txt)](https://github.com/DianaCortezL/ISB-Grupo-5/tree/88e031b9ee680d6403ba408c9e73f99652f8cca3/Otros/Archivos%20varios)
- [Procesamiento ECG (Jupyter Notebook)](https://github.com/DianaCortezL/ISB-Grupo-5/blob/19ff03aa9ecb7bfd3b8092b4e4bf92c544287deb/ISB/Laboratorios/Lab08%20-%20Transformada%20de%20Wavelet/ECG/ECG_wavelet.ipynb)

## **Conclusiones** <a name="id6">
   - 
   - 
   - 
## **Referencias bibliográficas** <a name="id7"></a>
[1] 

[2] 
 
[4] 

