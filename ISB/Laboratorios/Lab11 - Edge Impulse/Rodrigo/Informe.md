# **LABORATORIO 11: DATOS ESTRUCTURADOS / EDGE IMPULSE**
Nombre: Rodrigo Italo Llachua Inocente\
Código: 74285456\
Link del proyecto de Edge Impulse: https://studio.edgeimpulse.com/public/560551/live

## **Metodología** 
Para el desarrollo de este laboratorio es necesario el uso de la interfaz Edge Impulse, los datos a analizar son correspondientes a señales ECG obtenidos mediante Bitalino en los laboratorios pasados. Para el análisis de datos se tomó en cuenta las siguientes características: Estado Basal, Manteniendo la respiración, Post-Respiración, Post-Ejercicio y datos obtenidos mediante un simulador.

## **Procedimiento** 
1. **Conversión de archivos .txt a .csv:** Se hizo uso de un código de Python el cual convirtió los archivos descargados en formato .txt a .csv, adicionalmente filtró las columnas con información relevante.


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
input_folder = "C:/Users/hp/Desktop/Lab5_ECG"
output_folder =  "C:/Users/hp/Desktop/datos_ECG_csv"

# Llamar a la función para procesar los archivos
procesar_carpeta_txt_a_csv(input_folder, output_folder)
```
2. **Configuración de CSV Wizard:** A continuación se presenta la configuración realizada en la plataforma Edge Impulse en el apartado "CSV Wizard".
```json
{
    "version": 1,
    "fileName": "EjercicioD1.csv",
    "created": 1731896077701,
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
3.**Subida de data a Edge Impulse:**
Se procedió a subir todos los archivos previamente convertidos a formato .csv.
<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/19712214149414ae42c598dc2076d3ab74b77ebf/ISB/Laboratorios/Lab11%20-%20Edge%20Impulse/Joaquin/Imagenes/img3.png width="600" height="500"></p>
<div align="center">Figura 1: Datos en Edge Impulse</i></div>
</p>

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/19712214149414ae42c598dc2076d3ab74b77ebf/ISB/Laboratorios/Lab11%20-%20Edge%20Impulse/Joaquin/Imagenes/img3.png width="600" height="500"></p>
<div align="center">Figura 2: Relación Training/Test</i></div>
</p>
