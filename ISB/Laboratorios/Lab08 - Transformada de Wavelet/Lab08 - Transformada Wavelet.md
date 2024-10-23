# **LABORATORIO 8: – TRANSFORMADA WAVELET**
# **Tabla de contenidos**

1. [Introducción](#id1)
2. [Objetivos](#id2)
3. [Materiales y equipos](#id3)
4. [Métodología](#id4)
5. [Resultados](#id5)\
   5.1 [Señal ECG](#id6)\
   5.2 [Señal EMG](#id7)\
   5.3 [Señal EEG](#id8)\
   5.4 [Archivos](#id9)
7. [Conclusiones](#id10)
9. [Referencias bibliográficas](#id11)

## **Introducción** <a name="id1"></a>

## **Objetivos** <a name="id2"></a>
* Comprender los conceptos básicos de la transformada wavelet 
* Realizar el filtrado de las señales ECG, EMG y EEG utilizando la transformada wavelet
* Aplicar técnicas de wavelets para el procesamiento de señales enfocándose en la eliminación de ruido y la detección de características importantes

## **Materiales y equipos** <a name="id3"></a>
<div align="center">
   
|  **Modelo**  | **Descripción** | **Cantidad** |
|:------------:|:---------------:|:------------:|
|       -      |      Laptop     |       1      |
| - |   Python y librerías  |       -      |
<div align="center"> Tabla 1: Materiales y equipos</i></div>

</div>

## **Metodología** <a name="id4"></a>
El presente laboratorio consiste en diseñar filtros wavelet para señales EMG, ECG y EEG. Para ello se utilizarán las señales obtenidas previamente en los laboratorios. Se aplicará el filtro en 3 diferentes estados para cada una se las señales y el diseño de los filtros se basará literatura donde se obtendrán parámetros como: tipo de wavelet, nivel de descomposición y umbral. Una vez obtenido las características del filtro wavelet se realizará la descomposición de la señal por niveles para separar las distintas frecuencias de la señal en diferentes niveles, aislando detalles y elementos relevantes, conocidos como coeficientes. Por último, se realizará la reconstrucción de la señal a partir de los coeficientes wavelet modificados asegurando que los componentes clave de la señal permanecieran claros y definidos, facilitando su análisis.

- **Especificaciones del filtro wavelet para ECG**: Para el filtrado de ECG se tómo el siguiente artículo "ECG Signal Denoising Using Wavelet Thresholding Techniques in
Human Stress Assessment" [1]
  - Tipo de wavelet: db4
  - Nivel de descomposición: 6
  - Umbral: soft

- **Especificaciones del filtro wavelet para EMG**: Para el filtrado de EMG se tomó el artículo de título "An improved wavelet threshold denoising approach for surface electromyography signal" [2]
  - Tipo de wavelet: sym4
  - Nivel de descomposición: 10
  - Umbral: soft
    
- **Especificaciones del filtro wavelet para EEG**
  - Tipo de wavelet:
  - Nivel de descomposición:
  - Umbral:

## **Resultados** <a name="id5"></a>
### **Señal ECG** <a name="id6"></a>
- **Derivación 1: reposo**

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


- **Derivación 1: manteniendo la respiración por 10 segundos**

<p align="justify">
<p align="center"><img src="../../../Otros/Archivos_varios/Lab8_Wavelet/ECG2_level.jpg" width="500" height="550"></p>
<div align="center">Figura 2: Niveles de descomposición</i></div>
</p>

<div align="center">
   
|  **Señal sin filtrar**  | **Señal filtrada con transformada de Wavelt** |
|:------------:|:---------------:|
|<p align="center"><img src="../../../Otros/Archivos_varios/Lab8_Wavelet/ECG2_raw.jpg" width="500" height="270"></p>|<p align="center"><img src="../../../Otros/Archivos_varios/Lab8_Wavelet/ECG2_wave.jpg" width="500" height="270"></p>| 
<div align="center"> Tabla 3: Filtrado de señal EMG cuando se mantiene en reposo</i></div>

</div>

- **Derivación 1: después de una actividad física**

<p align="justify">
<p align="center"><img src="../../../Otros/Archivos_varios/Lab8_Wavelet/ECG3_level.jpg" width="500" height="550"></p>
<div align="center">Figura 3: Niveles de descomposición</i></div>
</p>

<div align="center">
   
|  **Señal sin filtrar**  | **Señal filtrada con transformada de Wavelt** |
|:------------:|:---------------:|
|<p align="center"><img src="../../../Otros/Archivos_varios/Lab8_Wavelet/ECG3_raw.jpg" width="500" height="270"></p>|<p align="center"><img src="../../../Otros/Archivos_varios/Lab8_Wavelet/ECG3_wave.jpg" width="500" height="270"></p>| 
<div align="center"> Tabla 4: Filtrado de señal EMG después de actividad física</i></div>

</div>


En la actividad 1 y 2 (reposo y manteniendo respiración) notamos de forma clara como la transformada de wavelet permite obtener una señal con menos ruido y manteniendo los picos P, T y el complejo QRS. Además, este método permite la eliminación de componentes de alta frecuencia que pueden corresponder a artefactos, ruido o red eleéctrica. Notamos que al reconstruir la señal se obtiene una más suave y sin mucho ruido. Los niveles 5 al 3 capturan principalmente ruido, que es eliminado luego de la umbralización. Los niveles 2 al 0 capturan detalles importantes y algunos artefactos. 

En el último nivel de descomposición (N=5), los coeficientes capturan principalmente las frecuencias más altas de la señal original, lo que incluye una gran cantidad de ruido. A medida que se avanza a los niveles N=4 y N=3, los coeficientes siguen reflejando componentes de alta frecuencia, aunque con una menor cantidad de ruido, permitiendo que los picos QRS aún sean visibles. En los niveles intermedios (N=2 a N=1), los coeficientes comienzan a representar mejor las variaciones de baja frecuencia, lo que reduce aún más el ruido y destaca las características globales de la señal. A partir de los niveles N=2, se capturan las tendencias más suaves y de muy baja frecuencia, con un menor nivel de ruido y una mayor claridad en los detalles finos de la señal. Finalmente, en el nivel N=1, predomina las variaciones de muy baja frecuencia, mostrando las tendencias generales de la señal original.


### **Señal EMG** <a name="id7"></a>
- Tricep en sobreesfuerzo:

<p align="justify">
<p align="center"><img src="../../../Otros/Archivos_varios/Lab8_Wavelet/ECG1_level.jpg" width="500" height="550"></p>
<div align="center">Figura 4: Niveles de descomposición (10)</i></div>
</p>
  
<div align="center">
   
|  **Señal sin filtrar**  | **Señal filtrada con transformada de Wavelt** |
|:------------:|:---------------:|
|<p align="center"><img src="../../../Otros/Archivos_varios/Lab8_Wavelet/ECG1_raw.jpg" width="500" height="270"></p>|<p align="center"><img src="../../../Otros/Archivos_varios/Lab8_Wavelet/ECG1_wave.jpg" width="500" height="270"></p>| 
<div align="center"> Tabla 3: Filtrado de señal EMG en sobreefuerzo</i></div>

</div>  

### **Señal EEG** <a name="id8"></a>
   
### **Archivos** <a name="id9"></a>
- [Documentos (.txt)](https://github.com/DianaCortezL/ISB-Grupo-5/tree/88e031b9ee680d6403ba408c9e73f99652f8cca3/Otros/Archivos%20varios)
- [Programa de ploteo ECG (Jupyter Notebook)](https://github.com/DianaCortezL/ISB-Grupo-5/blob/19ff03aa9ecb7bfd3b8092b4e4bf92c544287deb/ISB/Laboratorios/Lab08%20-%20Transformada%20de%20Wavelet/ECG/ECG_wavelet.ipynb)
- [Programa de ploteo EMG (Jupyter Notebook)](https://github.com/DianaCortezL/ISB-Grupo-5/blob/5fef37bacd236676dc3a4800ffb80b7bd5016f02/ISB/Laboratorios/Lab08%20-%20Transformada%20de%20Wavelet/EMG/EMG_wavelet.ipynb)
- [Programa de ploteo EEG (Jupyter Notebook)](https://github.com/DianaCortezL/ISB-Grupo-5/blob/19ff03aa9ecb7bfd3b8092b4e4bf92c544287deb/ISB/Laboratorios/Lab08%20-%20Transformada%20de%20Wavelet/EEG/EEG_code.ipynb)

## **Conclusiones** <a name="id10"></a>
   - Se empleó correctamente la transformada wavelet para cada tipo de señal biomédica, esta transformada tomó los parámetros acorde a cada artículo referenciado.
   - Se realizó una búsqueda detalla de artículos, donde se definían los parámetros adecuados para el filtrado de cada tipo de señal.
   - Se demostró la diferencia entre la señal original y la señal filtrada, dando como resultado una señal mucho más limpia de ruido.

## **Referencias bibliográficas** <a name="id11"></a>
[1] P. Karthikeyan, M. Murugappan, and S. Yaacob, “ECG signal denoising using wavelet thresholding techniques in human stress assessment,” Int. J. Electr. Eng. Inform., vol. 4, no. 2, p. 306, 2012.

[2] X. Zhang, Y. Liu, and Z. Li, “An improved wavelet threshold denoising approach for surface electromyography signal,” *EURASIP J. Adv. Signal Process.*, vol. 2020, no. 1, p. 12, 2020.

[3] 
 
[4] 
