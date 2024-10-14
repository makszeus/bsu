import numpy as np
from scipy.optimize import newton
from scipy.integrate import quad
import matplotlib.pyplot as plt

# Параметры задачи
R = 8 # Радиус шара
A = 1 # Начальное распределение температуры
a = 0.5 # Коэффициент теплопроводности
N = 10 # Количество членов в ряде
T = 4 # Значение времени t на правой границе

eps = 10**(-6)

mu = np.array([(i) * np.pi for i in range (N)])

def phi(x): return A * (R - x)

# Вычисляем коэффициенты a_n
def integrand(ro, n):
	return ro * phi(ro) * np.sin(mu[n] * ro / R)

a_n = np.array([2 / R * quad(integrand, 0, R, args=(n))[0] for n in range(N)])

# Функция для вычисления температуры в зависимости от r и t
def u(r, t):
	return np.sum([a_n[n] * np.exp(-(a * mu[n] / R) ** 2 * t) * np.sin(mu[n] * r / R) for n in range(N)])

# Построение графика
# Функция для вычисления температуры в зависимости от r и t
u_vect = np.vectorize(u)

# Построение графика
r = np.linspace(0 + eps, R, 500)
t = np.linspace(0 + eps, T, 10)

plt.figure(figsize=(16, 9))
for time in t:
	plt.plot(r, u_vect(r, time), label=f't={time}')

plt.xlabel('r')
plt.ylabel('u')
plt.title('Распределение температуры в шаре')
plt.grid(True)
plt.show()