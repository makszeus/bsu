import numpy as np
import matplotlib.pyplot as plt

N = 30 # Максимальное число шагов по r
K = 30 # Максимальное число шагов по t
R = 8 # Значение расстояния R на правой границе
T = 4 # Значение времени t на правой границе
h = R / N # Шаг сетки по r
t = T / K # Шаг сетки по t
a = 0.5 # Коэффициент теплопроводности
A = 1 # Константа
eps = 10**(-6)

# Инициализация сетки
x_i = np.arange(0 + eps, R, h) # Значения в узлах по r
t_j = np.arange(0 + eps, T, t) # Значение в узлах по t
r_i = len(x_i) # Число узлов по r
r_j = len(t_j) # Число узлов по t
u = np.zeros([r_j, r_i]) # Искомая сетка

# Начальное распределение температуры
def f_st(x): return np.cos(x)

# Вычисление начального распределения температуры
u[0] = f_st(x_i)

# Вычисление устойчивого условия
const = t / (h**2)
const2 = 1 / (2*(a**2))
print("t / h^2 =", float('{:.3f}'.format(const))) # Вывод значения t / h^2
print("1 / 2a^2 = ", float('{:.3f}'.format(const2))) # Вывод значения 1 / 2a^2

for j in range(len(u) - 1):
	for i in range(len(u[j]) - 1):
		u[j + 1, i] = u[j, i] + (a**2) * const * (u[j, i+1] - 2 * u[j, i] + u[j, i - 1])

		# Граничные условия
		u[j, 0] = 0
		u[j, len(u[j]) - 1] = 0

plot_ = np.arange(0, 30, 2)
plt.figure(figsize=(16, 9))

plt.xlabel('r')
plt.ylabel('u(r,t)')
plt.grid(True)
for y in plot_:
	plt.plot(x_i, u[y])