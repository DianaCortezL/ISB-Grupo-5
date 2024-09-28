# **LABORATORIO 5: – USO DE BITalino PARA EEG**
# **Tabla de contenidos**

1. [Introducción](#id1)
2. [Objetivos](#id2)
3. [Materiales y equipos](#id3)
4. [Conexión usada y procedimiento](#id4)
5. [Resultados](#id5)\
   5.1 [Señal con OpenBCI Ultracortex "Mark IV"](#id6)\
   5.2 [Señal con BITalino](#id7)\
   5.3 [Archivos](#id8)
7. [Conclusiones](#id9)
8. [Recomendaciones](#id10)
9. [Referencias bibliográficas](#id11)

## **Introducción** <a name="id1"></a>

### ¿Qué es EEG? ###
Qué es EEG, tipos de ondas y frecuencias

### Aplicaciones ###

### Tipos de medición de EEG ###

Describir que se hará en este lab

## **Objetivos** <a name="id2"></a>
* Adquirir señales biomédicas de EEG utilizando el Kit BITalino (R)evolution
* Obtener señales de EEG utilizando Ultracortex Mark IV EEG Headset y la tarjeta de biosensado Cyton de 8 canales.
* Plotear las señales en dominio del tiempo y frecuencia en Python

## **Materiales y equipos** <a name="id3"></a>
<div align="center">
   
|  **Modelo**  | **Descripción** | **Cantidad** |
|:------------:|:---------------:|:------------:|
| (R)EVOLUTION |   Kit BITalino  |       1      |
|       -      |      Laptop     |       1      |
|       -      |    Electrodos   |       3      |
|    OpenBCI   |    Ultracortex Mark IV EEG Headset   |       1      |
|    OpenBCI   |   OpenBCI Cyton 8-channel Board   |       1      |
<div align="center"> Tabla 1: Materiales y equipos</i></div>

</div>

<p align="justify">
<p align="center"><img src="../../../Otros/Imagenes/Lab6_EEG/Ultracortex.jpg" width="400" height="350"></p>
<div align="center">Figura 2:  Ultracortex Mark IV EEG Headset</i></div>
</p>  


<p align="justify">
<p align="center"><img src="../../../Otros/Imagenes/Lab6_EEG/BITalino.png" width="400" height="400"></p>
<div align="center">Figura 3:  BITalino y electrodos</i></div>
</p>

## **Conexión usada y procedimiento** <a name="id4"></a>
### **Conexión usada** 
* BITalino Board + Electrodos
* UltraCortex MARK IV + Tarjeta Cyton

</div>

<p align="justify">
<p align="center"><img src="../../../Otros/Imagenes/Lab4_EMG/bitalino.jpg" width="400" height="266"></p>
<div align="center">Figura 3: Conexión usada del BITalino y electrodos</i></div>
</p>

### **Procedimiento - Obtención de señales EEG** 
Para la obtención de la señal EEG con el BITalino y el UltraCortex MARK IV se utilizó el siguiente procedimiento:
- Se registró una línea base de la señal EEG con poco ruido y sin movimientos (respiración normal, sin movimientos oculares / ojos cerrados) durante 30 segundos.
- Se registró la señal EEG repitiendo 5 ciclos de 10 segundos de ojos abiertos - ojos cerrados
- Se registró la señal EEG en reposo durante 30 segundos nuevamente
- Se registró la señal EEG en un estado de razonamiento lógico-matemático a través de preguntas fáciles y complejas.

## **Resultados** <a name="id5"></a>
### **Señal con OpenBCI Ultracortex "Mark IV"** <a name="id6"></a>
- ### **Gráficos en OpenBCI GUI**
  
<div align="center">
 
|         **Fase**        |                                              **Video**                                   |   **Gráfico en OpenBCI GUI**    |
|:-------------------------------------:|:---------------------------------------------------------------------:|:---------------------------:|
|                **Fase de referencia de 30 segundos**                  | |
|                **Realizando secuencia de ojos abiertos - ojos cerrados**                 | |
|                **Respondiendo preguntas categoría simple**                | |
|                **Respondiendo preguntas categoría compleja**                | |

</div>

### **Señal con BITalino** <a name="id7"></a>
- ### **Gráficos en OpenBCI GUI**
A continuacion mostraremos los graficos ploteados en Open Signals.
<div align="center">
 
|         **Fase**        |  **Gráfico en OpenSignals**    |
|:-------------------------------------:|:---------------------------------------------------------------------:|
|                **Fase de referencia de 30 segundos**                  | |
|                **Realizando secuencia de ojos abiertos - ojos cerrados**                 | |
|                **Respondiendo preguntas categoría simple**                | |
|                **Respondiendo preguntas categoría compleja**                | |

</div>

- ### **Gráficos en Python**
Asimismo, se realizo el ploteo de las señales de OpenSignals en Python.

### **Archivos** <a name="id8"></a>
- [Documentos (.txt)](https://github.com/DianaCortezL/ISB-Grupo-5/tree/88e031b9ee680d6403ba408c9e73f99652f8cca3/Otros/Archivos%20varios/Lab6_EEG)
- [Programa de ploteo (Jupyter Notebook)](https://github.com/DianaCortezL/ISB-Grupo-5/blob/01dd208ed2c0990ba65ef55da91e29f922fbb739/ISB/Laboratorios/Lab06%20-%20Adquisi%C3%B3n%20de%20se%C3%B1al%20EEG/LabEEG.ipynb)

## **Conclusiones** <a name="id9"></a>
   - 

## **Recomendaciones** <a name="id10"></a>
   - 


## **Referencias bibliográficas** <a name="id11"></a>
[1] 
