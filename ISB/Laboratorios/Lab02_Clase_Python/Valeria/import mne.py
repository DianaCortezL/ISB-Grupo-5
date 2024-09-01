import mne
import matplotlib.pyplot as plt
import matplotlib
matplotlib.use('Qt5Agg')  # O 'TkAgg' si 'Qt5Agg' no funciona

from mne.datasets import sample

# Cargar el dataset de ejemplo proporcionado por MNE
data_path = sample.data_path()
raw_fname = str(data_path) + '/MEG/sample/sample_audvis_raw.fif'  # Convertir data_path a str

# Leer los datos crudos
raw = mne.io.read_raw_fif(raw_fname, preload=True)

# Mostrar información básica sobre los datos
print(raw.info)

# Visualizar los datos crudos
raw.plot(n_channels=10, duration=5, show=True)

# Mostrar el montaje de los electrodos
montage = raw.get_montage()
mne.viz.plot_montage(montage)

# Forzar la visualización
plt.show()
