# Nuestro código
```python 
import numpy as np
import pandas as pd
import scipy.signal as signal
import matplotlib.pyplot as plt

# Función para cargar datos CSV
def load_emg_data(file_path):
    """
    Carga los datos EMG desde un archivo CSV.
    :param file_path: Ruta del archivo CSV.
    :return: DataFrame con los datos cargados.
    """
    return pd.read_csv(file_path)

# Filtros Butterworth
def butter_bandpass_filter(data, lowcut, highcut, fs, order=4):
    """
    Aplica un filtro pasabanda Butterworth.
    :param data: Señal cruda EMG.
    :param lowcut: Frecuencia de corte inferior.
    :param highcut: Frecuencia de corte superior.
    :param fs: Frecuencia de muestreo.
    :param order: Orden del filtro.
    :return: Señal filtrada.
    """
    nyquist = 0.5 * fs
    low = lowcut / nyquist
    high = highcut / nyquist
    b, a = signal.butter(order, [low, high], btype='band')
    return signal.filtfilt(b, a, data)

def butter_highpass_filter(data, cutoff, fs, order=4):
    """
    Aplica un filtro paso alto Butterworth.
    :param data: Señal cruda EMG.
    :param cutoff: Frecuencia de corte.
    :param fs: Frecuencia de muestreo.
    :param order: Orden del filtro.
    :return: Señal filtrada.
    """
    nyquist = 0.5 * fs
    high = cutoff / nyquist
    b, a = signal.butter(order, high, btype='high')
    return signal.filtfilt(b, a, data)

# Filtro Notch
def notch_filter(data, fs, freq=50, quality=30):
    """
    Aplica un filtro Notch para eliminar interferencia eléctrica.
    :param data: Señal cruda EMG.
    :param fs: Frecuencia de muestreo.
    :param freq: Frecuencia de interferencia (50 Hz o 60 Hz).
    :param quality: Factor de calidad.
    :return: Señal filtrada.
    """
    nyquist = 0.5 * fs
    freq = freq / nyquist
    b, a = signal.iirnotch(freq, quality)
    return signal.filtfilt(b, a, data)

# Rectificación
def rectify_signal(data):
    """
    Aplica rectificación absoluta a la señal EMG.
    :param data: Señal EMG.
    :return: Señal rectificada.
    """
    return np.abs(data)

# Cálculo del RMS
def calculate_rms(data, window_size):
    """
    Calcula la envolvente de la señal mediante el método RMS.
    :param data: Señal EMG.
    :param window_size: Tamaño de la ventana para el cálculo del RMS.
    :return: Señal RMS.
    """
    squared = np.power(data, 2)
    window = np.ones(window_size) / window_size
    rms = np.sqrt(np.convolve(squared, window, mode='same'))
    return rms

# Visualización de datos
def plot_signals(original, filtered, rectified, rms, fs):
    """
    Genera gráficos para comparar la señal original, filtrada, rectificada y RMS.
    :param original: Señal original.
    :param filtered: Señal filtrada.
    :param rectified: Señal rectificada.
    :param rms: Señal RMS.
    :param fs: Frecuencia de muestreo.
    """
    time = np.arange(len(original)) / fs

    plt.figure(figsize=(12, 8))
    
    plt.subplot(4, 1, 1)
    plt.plot(time, original)
    plt.title("Señal Original")
    plt.xlabel("Tiempo (s)")
    plt.ylabel("Amplitud")

    plt.subplot(4, 1, 2)
    plt.plot(time, filtered)
    plt.title("Señal Filtrada (Pasabanda + Notch)")
    plt.xlabel("Tiempo (s)")
    plt.ylabel("Amplitud")

    plt.subplot(4, 1, 3)
    plt.plot(time, rectified)
    plt.title("Señal Rectificada")
    plt.xlabel("Tiempo (s)")
    plt.ylabel("Amplitud")

    plt.subplot(4, 1, 4)
    plt.plot(time, rms)
    plt.title("Señal RMS")
    plt.xlabel("Tiempo (s)")
    plt.ylabel("Amplitud")

    plt.tight_layout()
    plt.show()

# Ejecución del procesamiento
def process_emg(file_path, fs=1000, lowcut=20, highcut=500, highpass_cutoff=10, rms_window_size=200):
    """
    Procesa la señal EMG desde un archivo CSV, aplicando filtros y análisis.
    :param file_path: Ruta del archivo CSV.
    :param fs: Frecuencia de muestreo.
    :param lowcut: Frecuencia de corte inferior del filtro pasabanda.
    :param highcut: Frecuencia de corte superior del filtro pasabanda.
    :param highpass_cutoff: Frecuencia de corte del filtro paso alto.
    :param rms_window_size: Tamaño de la ventana para el cálculo del RMS.
    """
    # Cargar datos
    data = load_emg_data(file_path)
    emg_signal = data['EMG'].values  # Asume una columna llamada 'EMG'

    # Filtrado
    bandpassed = butter_bandpass_filter(emg_signal, lowcut, highcut, fs)
    highpassed = butter_highpass_filter(bandpassed, highpass_cutoff, fs)
    notched = notch_filter(highpassed, fs)

    # Rectificación
    rectified = rectify_signal(notched)

    # Cálculo de RMS
    rms = calculate_rms(rectified, rms_window_size)

    # Visualización
    plot_signals(emg_signal, notched, rectified, rms, fs)

# Ejemplo de uso
# Cambia 'path_to_file.csv' por la ruta del archivo CSV con datos EMG
process_emg('path_to_file.csv')
```

