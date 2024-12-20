# **LABORATORIO 11: DATOS ESTRUCTURADOS / EDGE IMPULSE**
Nombre: Diana Isabel Cortez López\
Código: 71727300\
Link del proyecto de Edge Impulse: [https://studio.edgeimpulse.com/public/560046/live](https://studio.edgeimpulse.com/public/560552/live)  

## **Introducción** 
En este laboratorio se exploró el uso de la plataforma Edge Impulse para el análisis de datos ECG previamente trabajados en el laboratorio 5. Esta herramienta permite es útil para el manejo de señales biomédicas, haciendo más sencillas la estructuración y la evaluación de datos.  

## **Objetivo** 
El objetivo principal fue familiarizarse con las funcionalidades de Edge Impulse y evaluar su capacidad para manejar señales complejas, como las de ECG que fueron obtenidas en el laboratorio 5 con el uso de Bitalino, aplicando técnicas modernas de inteligencia artificial.
Las señales tomadas fueron:
- En estado basal
- Manteniendo la respiración
- Después de una respiración
- Después de realizar un ejercicio
- Con el simulador prosim

## **Metodología** 
1. Convertir los datos .txt a .csv
Dado que Edge Impulse no acepta datos en formato .txt se ha tenido que convertir los datos a .csv con python eliminando espacios en blanco y saltos de línea al principio y al final:

```python
import os
import numpy as np

def procesar_carpeta_txt_a_csv(input_folder, output_folder):
    """
    Convierte todos los archivos .txt en una carpeta a archivos .csv y los guarda en otra carpeta.
    
    Args:
    - input_folder: Ruta de la carpeta de entrada que contiene los archivos .txt.
    - output_folder: Ruta de la carpeta donde se guardarán los archivos .csv.
    """
    # Verificar que la carpeta de entrada exista
    if not os.path.exists(input_folder):
        print("La carpeta de entrada no existe.")
        return
    
    # Crear la carpeta de salida si no existe
    os.makedirs(output_folder, exist_ok=True)
    
    # Obtener la lista de archivos .txt en la carpeta de entrada
    txt_files = [f for f in os.listdir(input_folder) if f.endswith('.txt')]
    
    if not txt_files:
        print("No se encontraron archivos .txt en la carpeta de entrada.")
        return
    
    for txt_file in txt_files:
        input_path = os.path.join(input_folder, txt_file)
        output_path = os.path.join(output_folder, txt_file.replace('.txt', '.csv'))
        
        try:
            # Procesar el archivo .txt y guardarlo como .csv
            with open(input_path, "r") as f:
                # Saltar las tres primeras líneas
                for _ in range(3):
                    next(f)
                
                # Leer todas las líneas restantes
                all_data = f.readlines()
            
            # Procesar cada línea, dividiendo por tabulaciones
            all_data = [line.strip().split('\t') for line in all_data]
            
            sample = [int(row[0]) for row in all_data]  # Primera columna
            amplitude = [int(row[5]) for row in all_data]  # Sexta columna (índice 5)
            
            # Escribir los datos en el archivo CSV
            with open(output_path, "w") as f:
                for s, a in zip(sample, amplitude):
                    f.write(f"{s};{a}\n")
            
            print(f"Convertido: {txt_file} -> {os.path.basename(output_path)}")
        
        except Exception as e:
            print(f"Error al procesar {txt_file}: {e}")

# Rutas de las carpetas de entrada y salida
input_folder = "C:/Users/Diana/Desktop/Lab5_ECG"
output_folder =  "C:/Users/Diana/Desktop/ECG_csv"

# Llamar a la función para procesar los archivos
procesar_carpeta_txt_a_csv(input_folder, output_folder)
```

Los datos en formato .csv se ecuentran en la siguiente carpeta: C:\Users\diana\OneDrive\Escritorio\Repositorio\ISB-Grupo-5\ISB\Laboratorios\Lab11 - Edge Impulse\Diana\Mis datitos csv

De esta manera los datos pasan a verse en csv
<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/f61031da1f21d0d317a5a55db7fa280d4c6512ce/ISB/Laboratorios/Lab11%20-%20Edge%20Impulse/Diana/Imagenes/datos_en_csv.png width="600" height="300"></p>
<div align="center">Figura 1: Conversión a .csv</i></div>
</p>

2.  Creo sesión y proyecto en Edge Impulse
<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/b75790883d68dc8f2926c159f27c284642512e96/ISB/Laboratorios/Lab11%20-%20Edge%20Impulse/Diana/Imagenes/Sesi%C3%B3n_y_proyecto.png width="600" height="300"></p>
<div align="center">Figura 2: proyecto creado en Edge Impulse </i></div>
</p>

3. Configuración usada:

```json
{
    "version": 1,
    "fileName": "postRespD1.csv",
    "created": 1731896078906,
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
4. Se subieron los datos y se dividieron en las siguientes etiquetas:
   3.1. Ejercicio
   3.2. Post-Resp
   3.3. Reposo
   3.4. SIM
   
5. Se editó la ubicación de los datos entre training set y test set hasta llegar al ratio adecuado

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/afc708aa64898b6d93ef21135d8cc937607856bc/ISB/Laboratorios/Lab11%20-%20Edge%20Impulse/Diana/Imagenes/Datos_edge_impulse.png width="800" height="500"></p>
<div align="center">Figura 3: Repartición 80-20</i></div>
</p>

## **Resultados**  
Se logró cargar exitosamente el conjunto de datos de ECG en la plataforma Edge Impulse y se obtuvo un buen ratio TRAIN/TEST
