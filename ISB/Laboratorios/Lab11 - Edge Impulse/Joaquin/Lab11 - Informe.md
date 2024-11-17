# **LABORATORIO 11: DATOS ESTRUCTURADOS / EDGE IMPULSE**
Nombre: Joaquín Miguel Díaz Lara\
Código: 73707854\
Link del proyecto de Edge Impulse: https://studio.edgeimpulse.com/public/560046/live  

## **Metodología** 
Para este laboratorio se usó la data obtenida en el Laboratorio 5 correspondiente a ECG. Esta data fue obtenida mediante el uso del Bitalinno y luego fue subida a Edge Impulse en formato .csv. Se utilizaron los datos de las tres derivaciones bipolares cuando la persona se ecuentra en:
- estado basal
- manteniendo la respiración
- post respiración
- después de realizar un ejercicio
- simulador prosim

## **Convertir datos .txt a .csv** 
Dado que Edge Impulse no acepta datos en formato .txt se ha tenido que convertir los datos a .csv. Para ello se implentó un código en python que realice este procedimiento. Cada línea se procesa y se elimina espacios en blanco y saltos de línea al principio y al final. Además, se divide la línea en columnas usando el carácter de tabulación (\t) como separador. El código procesa una carpeta que contiene varios archivos .txt, extrae datos específicos de cada archivo y guarda el resultado en una nueva carpeta como archivos .csv. En total se obtuvo 16 archivos .csv. A continuación, se muestra el código utilizado: 

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
input_folder = "C:/Users/Joaquin/Desktop/Lab5_ECG"
output_folder =  "C:/Users/Joaquin/Desktop/datos_ECG_csv"

# Llamar a la función para procesar los archivos
procesar_carpeta_txt_a_csv(input_folder, output_folder)
```

Los datos en formato .csv se ecuentran en la siguiente carpeta: [Datos_ECG_csv_Joaquin](https://github.com/DianaCortezL/ISB-Grupo-5/tree/cf42105267383d59ea5dced92c8e2cb5bea2d2cb/ISB/Laboratorios/Lab11%20-%20Edge%20Impulse/Joaquin/Datos_ECG_csv_Joaquin)

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/cf42105267383d59ea5dced92c8e2cb5bea2d2cb/ISB/Laboratorios/Lab11%20-%20Edge%20Impulse/Joaquin/Imagenes/Img1.png width="600" height="300"></p>
<div align="center">Figura 1: Conversión de .txt a .csv</i></div>
</p>

## **Archivo modelo CSV WIZARD** 
1. Se procedió a crear el proyecto en Edge Impulse
<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/ea53e2bb281935420fe7d062eae1931f878dbb76/ISB/Laboratorios/Lab11%20-%20Edge%20Impulse/Joaquin/Imagenes/Img2.png width="600" height="300"></p>
<div align="center">Figura 2: proyecto creado en Edge Impulse </i></div>
</p>

2. Se realizó la configuración de CSV WIZARD
```json
{
    "version": 1,
    "fileName": "reposoD1.csv",
    "created": 1731794829040,
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
## **Subida de datos a Edge Impulse** 
‌Luego de haber realizado la configuración del CSV WIZARD, se procedió a subir los archivos. Para esto, se agruparon los archivos en 5 etiqutas: EJERCICIO, POSTRESPIRACION, REPOSO, RESPIRACION y SIMULADOR. En la Fig. 3 se observa la clasificación de las señales en base a la actividad realizada.

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/19712214149414ae42c598dc2076d3ab74b77ebf/ISB/Laboratorios/Lab11%20-%20Edge%20Impulse/Joaquin/Imagenes/img3.png width="600" height="500"></p>
<div align="center">Figura 3: Dataset filter</i></div>
</p>

Se realizaron movimientos de los datos entre Training y Set para obtener un mejor Dataset train / test split ratio. Finalmente, el data set que se generó se observa en la Fig. 4. Observamos que se obtuvo un ratio de 71%/29% lo cual es un modelo adecuado y preciso. 

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/cabe4950d5a5b0086a2a01962b1a039bde012879/ISB/Laboratorios/Lab11%20-%20Edge%20Impulse/Joaquin/Imagenes/img4.png width="700" height="300"></p>
<div align="center">Figura 4: Dataset final</i></div>
</p>

<p align="justify">
<p align="center"><img src=https://github.com/DianaCortezL/ISB-Grupo-5/blob/dbcc927561f270816e193ebfb0772264eab484d2/ISB/Laboratorios/Lab11%20-%20Edge%20Impulse/Joaquin/Imagenes/img5.png width="700" height="500"></p>
<div align="center">Figura 5: Dataset train / test split ratio</i></div>
</p>
