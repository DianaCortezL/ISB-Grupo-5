# **LABORATORIO 4: – USO DE BITalino PARA EMG**
# **Tabla de contenidos**

1. [Introducción](#id1)
2. [Objetivos](#id2)
3. [Materiales y equipos](#id3)
4. [Resultados](#id4)\
   4.1 [Conexión usada](#id5)\
   4.2 [Prueba 1: Bícep braquial](#id6)\
   4.3 [Prueba 2: Músculo aductor del pulgar](#id7)\
   4.4 [Prueba 3: Músculo gastrocnemio](#id8)\
   4.5 [Prueba 4: Tricep braquial](#id9)\
   4.6 [Archivos utilizados](#id10)
6. [Conclusiones](#id11)
7. [Recomendaciones](#id12)
6. [Referencias bibliográficas](#id13)

## **Introducción** <a name="id1"></a>
La señal electromiográficas (EMG) es una representación del campo de potencial eléctrico generado por la despolarización de la membrana externa de la fibra muscular (sarcolema). La señal EMG es generada por la actividad eléctrica de las fibras musculares durante una contracción. Las fuentes de la señal son las zonas de despolarización y repolarización de las fibras musculares [1]. El rango de amplitud de la señal EMG es de 0 a 10 mV (+5 a -5) antes de la amplificación [2]. La señal EMG tiene muchas aplicaciones en dispositivos de rehabilitación o prostéticos, ciencias del deporte y neurofisiología [3].

Para detectar esta señal se utilizan:
- **Electrodos intrsmusculares o de aguja**: método invasivo donde un electrodo de aguja se introduce directamente en el músculo. La inserción directa en el músculo permite la detección de potenciales eléctricos muy cerca de la fuente. Es un método más preciso y menos susceptible a interferencias.  
- **Electrodos superficiales (sEMG)**: método no invasivo donde se colocan electrodos de superfice sobre la piel, directamente en los músculos que se desea estudiar. Es un método fácil de realizar; sin embargo, es limitante solo a músculos superficiales y puede ser generar interferencias con la piel, músculos adyacentes o ruido eléctrico.

**Concepto de potencial de acción de la unidad motora (MUAP) en sEMG [3]**  
La distribución de voltaje del sEMG en la piel corresponde a la suma de los potenciales de acción de las unidades motoras (MUAP) que se generan por las MU (unidad motora) activadas. Las MU representan la unidad básica del músculo, compuesta por una neurona motora y todas las fibras musculares que esta inerva. Cuando un potencial de acción axonal alcanza la unión neuromuscular, se libera acetilcolina, lo que desencadena un potencial de acción en las fibras musculares. En este sentido, cada MUAP es la suma de potenciales de acción superficiales producidos por la fibras individuales de cada unidad motor (MU) y el sEMG es la suma de estos MUAP.

<p align="justify">
<p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/MUAP.png" width="400" height="266"></p>
<div align="center"> Figura 1: Representación esquemática de las fibras de dos unidades motoras [3]</i></div>
<p>

En el presente laboratorio, se utilizará la plataforma BITalino para poder **adquirir señal de EMG mediante electrodos de superficie (sEMG) de 4 músculos distintos: bícep braquial, músculo aductor del pulgar, músculo gastrocnemio y tricep braquial**. Para cada músculo se relizará prueba en 3 diferentes movimientos (reposo, sin oposición, con oposición), se obtendrán las señales y se graficarán en Python para su visualización y discusión.

## **Objetivos** <a name="id2"></a>
* Adquirir señales biomédicas de EMG.
* Hacer una correcta configuración de BiTalino.
* Extraer la información de las señales EMG del software OpenSignals (r)evolution
* Plotear las señales en dominio del tiempo y frecuencia en Python

## **Materiales y equipos** <a name="id3"></a>
<div align="center">

|  **Modelo**  | **Descripción** | **Cantidad** |
|:------------:|:---------------:|:------------:|
| (R)EVOLUTION |   Kit BITalino  |       1      |
|       -      |      Laptop     |       1      |
|       -      |    Electrodos superficiales   |       3      |
<div align="center"> Tabla 1: Materiales y equipos</i></div>


</div>

<p align="justify">
<p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/image_materiales.jpg" width="400" height="266"></p>
<div align="center">Figura 2: Kit BITalino y electrodos de superficie</i></div>
</p>


## **Resultados** <a name="id4"></a>
### **Conexión usada** <a name="id5"></a>
Se utilizó la conexión EMG en la placa Bitalino utilizando el sensor EMG de 3 electrodos como se muestra a continuación.
<p align="justify">
<p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/bitalino.jpg" width="400" height="266"></p>
<div align="center">Figura 3: Conexión usada del BITalino y electrodos</i></div>
</p>

El siguiente procedimiento consiste en colocar los electrodos EMG en el usuario de prueba. Para ello se utilizó la Guía De Procedimiento de Electromiografía y Velocidad de Conducción de nervios periféricos (2020) elaborada por el Instituto Nacional del Niño de San Borja para el Ministerio de Salud (MINSA) - GP-001/INSNSB/UAIE/SUAIEPSE – NEUROLOGIA PEDIATRICA V01 (RD N° 000226-2020-DG-INSNSB) [4].

### **Prueba 1: Bícep braquial** <a name="id6"></a>
Se escogió el músculo al ser superficial y de fácil identificación. La ubicación de los electrodos fue guiada a partir de las indicaciones propuestas por la publicación de nombre "Análisis de las señales EMG de superficie del bíceps durante la ejecución de ejercicios con pesas" (2 electrodos sobre el bicel braquial en formato serie y un electrodo de referencia, el cual puede ser colocado en el codo o muñeca) y se realizaron pruebas en reposo, esfuerzo sin oposición y esfuerzo con oposición para analizar el cambio de señal.
<p align="justify">
<p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/Biceps1.jpg" width="600" height="300"></p>
<div align="center">Figura 4: Posicionamiento de electrodos para la obtención de señales en el bíceps braquial derecho.</i></div>
</p>

<div align="center">
   
|  **Reposo**  | **Sin oposición** | **Con oposición** |
|:------------:|:---------------:|:------------:|
|<video src="https://user-images.githubusercontent.com/b49875f0-82ef-4d27-a2aa-e8e5e6103e9a.mp4"></video>|<video src="https://user-images.githubusercontent.com/092f3871-e25f-4d7b-a778-03641931fcaf.mp4"></video>|<video src= "https://user-images.githubusercontent.com/36d881ed-29d1-4178-844e-4b9741314f90.mp4"></video>|

<p align="justify">
<div align="center">Para mejor visualización de los videos dar click en el ícono de Youtube</i></div>
</p>  

[<img src="https://cdn.icon-icons.com/icons2/1713/PNG/512/iconfinder-videologoplayicon-3993847_112649.png" width="20%" height="20%">](https://www.youtube.com/playlist?list=PLKyz-4YrUo3Q4-50zDqIl1RbkGDer-eyK)
</div>

- ### **Ploteo de la señal en Python: Dominio del tiempo y frecuencia**
   A coninuación se muestran la data obtenida en el dominio del tiempo y dominio de la frecuencia
   - Reposo
     <p align="justify">
     <p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/Biceps_graficas_reposo.jpg" width="650" height="500"></p>
     </p>
   - Sin oposición
     <p align="justify">
     <p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/Biceps_graficas_sin_oposicion.jpg" width="650" height="500"></p>
     </p>
   - Con oposición
     <p align="justify">
     <p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/Biceps_graficas_oposicion.jpg" width="650" height="500"></p>

### **Prueba 2: Músculo aductor del pulgar** <a name="id7"></a>
El músculo abductor corto del pulgar (ACP) pertenece al primer plano muscular subfascial de la región tenar de gran importancia en los movimientos del pulgar. 
La ubicación de los electrodos fue la siguiente según la GUÍA DE PROCEDIMIENTO DE ELECTROMIOGRAFÍA Y VELOCIDAD DE CONDUCCIÓN DE NERVIOS PERIFÉRICOS del Instituto Nacional del Niño de San Borja:
Electrodo activo (G1): Colocar sobre el centro del músculo abductor corto del pulgar 
(ACP), un tercio de la distancia entre el pliegue carpo metacarpiano y la articulación 
metacarpo falángica del pulgar (1er dedo). 
Electrodo de referencia (G2): Colocar sobre la articulación metacarpo falángico del 
primer dedo, distal al electrodo activo. 
Electrodo tierra: Colocado en el dorso de la mano.
<p align="justify">
<p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/aductor pulgar.jpg" width="650" height="250"></p>
<div align="center">Figura 5: Posicionamiento de electrodos para la obtención de señales en el mùculo aductor del pulgar derecho.</i></div>
</p>

<div align="center">
   
|  **Reposo**  | **Sin oposición** | **Con oposición** |
|:------------:|:---------------:|:------------:|
|<video src="https://user-images.githubusercontent.com/67a14538-64fe-4a2a-a8d6-a3e4a3f076d5.mp4"></video>|<video src="https://user-images.githubusercontent.com/af3715f6-c9ae-4d9e-88d6-e9c4592ccc69.mp4"></video>|<video src= "https://user-images.githubusercontent.com/077e5478-1f01-4cbe-a1b1-619135a5ab11.mp4"></video>|

<p align="justify">
<div align="center">Para mejor visualización de los videos dar click en el ícono de Youtube</i></div>
</p>  

[<img src="https://cdn.icon-icons.com/icons2/1713/PNG/512/iconfinder-videologoplayicon-3993847_112649.png" width="20%" height="20%">](https://www.youtube.com/playlist?list=PLKyz-4YrUo3R1rk6B5YFyBnburL7kmY8D)
</div>

- ### **Ploteo de la señal en Python: Dominio del tiempo y frecuencia**
   A coninuación se muestran la data obtenida en el dominio del tiempo y dominio de la frecuencia
   - Reposo
     <p align="justify">
     <p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/Pulgar_graficas_reposo.jpg" width="650" height="500"></p>
     </p>
   - Sin oposición
     <p align="justify">
     <p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/Pulgar_graficas_sin_oposicion.jpg" width="650" height="500"></p>
     </p>
   - Con oposición
     <p align="justify">
     <p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/Pulgar_graficas_oposicion.jpg" width="650" height="500"></p>
     </p>

### **Prueba 3: Músculo gastrocnemio** <a name="id8"></a>
Se eligió el gastronemio por su fácil localización y sencilla activación del músculo.
Los electrodos se ubicaron de la siguiente manera:
Electrodo 1: Ubicado en la piel superficial al músculo, zona anterior de la pierna
Electrodo 2: Ubicado en la piel superficial al músculo, zona anterior de la pierna, distanciado del primer electrodo verticalmente
Neutro: Ubicado en la parte superficial de la tibia.
<p align="justify">
<p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/Gastrocnemio.jpg" width="700" height="400"></p>
<div align="center">Figura 6: Posicionamiento de electrodos para la obtención de señales en el músculo gastrocnemio derecho.</i></div>
</p>

<div align="center">
   
|  **Reposo**  | **Esfuerzo** | **Sobreesfuerzo sin oposición** |
|:------------:|:---------------:|:------------:|
|<video src="https://user-images.githubusercontent.com/27d392ad-a041-4e54-8f90-0a6b14e80f0f.mp4"></video>|<video src="https://user-images.githubusercontent.com/75a6c4f4-0524-44a8-b6da-cfe3df00bb69.mp4"></video>|<video src= "https://user-images.githubusercontent.com/68bb1c7a-39ac-415c-a21c-0ae45fc841b5.mp4"></video>|

<p align="justify">
<div align="center">Para mejor visualización de los videos dar click en el ícono de Youtube</i></div>
</p>  

[<img src="https://cdn.icon-icons.com/icons2/1713/PNG/512/iconfinder-videologoplayicon-3993847_112649.png" width="20%" height="20%">](https://www.youtube.com/playlist?list=PLKyz-4YrUo3RR13SN4Ai1WwyWk6ezuXg1)

</div>

- ### **Ploteo de la señal en Python: Dominio del tiempo y frecuencia**
   A coninuación se muestran la data obtenida en el dominio del tiempo y dominio de la frecuencia
   - Reposo
     <p align="justify">
     <p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/Gastronecmio_graficas_reposo.jpg" width="650" height="500"></p>
     </p>
   - Esfuerzo
     <p align="justify">
     <p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/Gastronecmio_graficas_esfuerzo.jpg" width="650" height="500"></p>
     </p>
   - Sobreesfuerzo sin oposición
     <p align="justify">
     <p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/Gastronecmio_graficas_sobreesfuerzo.jpg" width="650" height="500"></p>
     </p>
     
### **Prueba 4: Tricep Braquial** <a name="id9"></a>
Se escogió el músculo al ser superficial y de fácil identificación igual que el de la prueba 1, pero considerando que está en la zona posterior del brazo y los movimientos de esfuerzo serán diferentes, se optó por la rotación. La ubicación de los electrodos fue guiada a partir de AAAAAAAAAAAAAAAAAA y se realizaron pruebas en reposo, esfuerzo sin oposición y esfuerzo con oposición para analizar el cambio de señal.
<p align="justify">
<p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/triceps.jpg" width="400" height="500"></p>
<div align="center">Figura 7: Posicionamiento de electrodos para la obtención de señales en el triceps braquial derecho.</i></div>
</p>  


<div align="center">
   
|  **Reposo**  | **Esfuerzo** | **Sobreesfuerzo sin oposición** |
|:------------:|:---------------:|:------------:|
|<video src="https://user-images.githubusercontent.com/3d2e256b-1b0b-45e6-881a-7c67814c92b9.mp4"></video>|<video src="https://user-images.githubusercontent.com/c606cd01-5a08-4b8c-a946-48103dcaaec7.mp4"></video>|<video src= "https://user-images.githubusercontent.com/d8ca2d70-d802-41ab-8d84-04cf8d5b42a7.mp4"></video>|

<p align="justify">
<div align="center">Para mejor visualización de los videos dar click en el ícono de Youtube</i></div>
</p>  

[<img src="https://cdn.icon-icons.com/icons2/1713/PNG/512/iconfinder-videologoplayicon-3993847_112649.png" width="20%" height="20%">](https://www.youtube.com/playlist?list=PLKyz-4YrUo3Q2SirQwFWpUK6rOJ3rqsKD)

</div>

- ### **Ploteo de la señal en Python: Dominio del tiempo y frecuencia**
   A coninuación se muestran la data obtenida en el dominio del tiempo y dominio de la frecuencia
   - Reposo
     <p align="justify">
     <p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/Triceps_graficas_reposo.jpg" width="650" height="500"></p>
     </p>
   - Esfuerzo
     <p align="justify">
     <p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/Triceps_graficas_esfuerzo.jpg" width="650" height="500"></p>
     </p>
   - Sobreesfuerzo sin oposición
     <p align="justify">
     <p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/Triceps_graficas_sobreesfuerzo.jpg" width="650" height="500"></p>
     </p>

### **Archivos** <a name="id10"></a>
- [Documentos (.txt)](https://github.com/DianaCortezL/ISB-Grupo-5/tree/faacf940cd92a67b1431c22d82b8411c5dae7d26/Otros/Archivos%20varios/Lab4_EMG)
- [Programa de ploteo (Jupyter Notebook)](https://github.com/DianaCortezL/ISB-Grupo-5/blob/be9da5dae231d9adf809ada70db73281b355ea1a/ISB/Laboratorios/Lab04%20-%20Adquisici%C3%B3n%20de%20se%C3%B1al%20EMG/LabEMG.ipynb)

## **Conclusiones** <a name="id11"></a>
   - Se logró obtener una clara diferencia entre las gráficas de reposo, esfuerzo y sobreesfuerzo o esfuerzo con oposición. Es posible notar que las gráficas en función del tiempo para los esfuerzos con oposición o sobreesfuerzo fueron las que alcanzaron mayores amplitudes.
   - Las gráficas en dominio de frecuencias no presentan una gran alteración entre ellas, esto es debido a que las frecuencias recibidas por los impulsos musculares no suelen variar significativamente, sin embargo, las amplitudes sí son fácilmente diferenciables en el dominio del tiempo.


## **Recomendaciones** <a name="id12"></a>
- Evitar que la tierra este muy distante de los otros dos electrodos para obtener una mejor señal.
- No utilizar músculos que tengan varios músculos subyacentes alrededor cuyas señales pueden generar ruido en la señal.
- Evitar hacer las pruebas en zonas con dispositivos electrónicos activados, estos pueden generar interferencia.


## **Referencias bibliográficas** <a name="id13"></a>
[1] D. Farina, D. F. Stegeman, and R. Merletti, “Biophysics of the Generation of EMG Signals,” Surface Electromyography : Physiology, Engineering, and Applications, pp. 1–24, Apr. 2016, doi: https://doi.org/10.1002/9781119082934.ch02.  

[2] D. Jiménez y J. Antonio, “Análisis de las señales EMG de superficie del bíceps durante la ejecución de ejercicios con pesas /”, Universidad Tecnológica de Bolívar, 2015.


[3]  M. B. I. Reaz, M. S. Hussain, and F. Mohd-Yasin, “Techniques of EMG signal analysis: detection, processing, classification and applications,” Biological Procedures Online, vol. 8, no. 1, pp. 11–35, Dec. 2006, doi: https://doi.org/10.1251/bpo115.  

[4] MINSA, GUÍA DE PROCEDIMIENTO DE ELECTROMIOGRAFÍA Y VELOCIDAD DE CONDUCCIÓN DE NERVIOS PERIFÉRICOS UNIDAD DE ATENCIÓN INTEGRAL ESPECIALIZADA SUB UNIDAD DE ATENCION INTEGRAL ESPECIALIZADA PEDIÁTRICA Y SUB ESPECIALIDADES NEUROLOGIA PEDIATRICA. Disponible en: https://www.insnsb.gob.pe/docs-trans/resoluciones/archivopdf.php?pdf=2020/RD%20N%C2%B0%20000226-2020-DG-INSNSB%20Gu%C3%ADa%20Proced%20Electromiograf%C3%ADa_2020%203REV%20UGC%20CHN%2019.06.2020.pdf  

[5] I. Campanini, A. Merlo, C. Disselhorst-Klug, L. Mesin, S. Muceli, and R. Merletti, “Fundamental Concepts of Bipolar and High-Density Surface EMG Understanding and Teaching for Clinical, Occupational, and Sport Applications: Origin, Detection, and Main Errors,” Sensors, vol. 22, no. 11, p. 4150, May 2022, doi: https://doi.org/10.3390/s22114150.

‌
