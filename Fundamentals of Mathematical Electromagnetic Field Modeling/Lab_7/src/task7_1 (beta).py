import numpy as np
import matplotlib.pyplot as plt

# Параметры сетки
N = 200
M = 1000
T = 1.0
h = 200.0 / N
τ = T / M

# Инициализация сетки
z = np.linspace(0, 200, N)
t = np.linspace(0, T, M)
E = np.zeros((M, N))
H = np.zeros((M, N))

# Начальные условия
E[0, :] = 0.1 * np.sin(2 * np.pi * z / 100)
H[0, :] = 0.1 * np.sin(2 * np.pi * z / 100)

# Разностная схема
for j in range(M - 1):
    for i in range(1, N - 1):
        E[j + 1, i] = E[j, i] - τ * (H[j, i + 1] - H[j, i - 1]) / (2 * h)
        H[j + 1, i] = H[j, i] - τ * (E[j, i + 1] - E[j, i - 1]) / (2 * h)

    # Граничные условия
    E[j + 1, 0] = E[j + 1, N - 1]
    H[j + 1, 0] = H[j + 1, N - 1]
    E[j + 1, N - 1] = E[j + 1, 0]
    H[j + 1, N - 1] = H[j + 1, 0]

# Построение графиков
plt.figure(figsize=(12, 6))
plt.subplot(121)
plt.imshow(E, aspect='auto', extent=[0, 200, 0, T], origin='lower')
plt.title('E(z, t)')
plt.xlabel('z')
plt.ylabel('t')

plt.subplot(122)
plt.imshow(H, aspect='auto', extent=[0, 200, 0, T], origin='lower')
plt.title('H(z, t)')
plt.xlabel('z')
plt.ylabel('t')

plt.tight_layout()
plt.show()
