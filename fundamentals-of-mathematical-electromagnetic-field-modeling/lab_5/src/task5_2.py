import numpy as np
from numpy.polynomial.laguerre import lagval, laggauss
import matplotlib.pyplot as plt

def f(x):
    return x**7

def scalar_product(f, g):
    return np.sum(f * g * x**2)

n = 6
x, w = laggauss(n+1)

A = np.zeros((n+1, n+1))
for i in range(n+1):
    for j in range(n+1):
        A[i,j] = scalar_product(lagval(x, [0]*i+[1], tensor=True), lagval(x, [0]*j+[1], tensor=True))
        
b = np.zeros(n+1)
for i in range(n+1):
    b[i] = scalar_product(f(x), lagval(x, [0]*i+[1], tensor=True))
    
c = np.linalg.solve(A, b)

x_plot = np.linspace(-100, 100, 100000)
y_plot = f(x_plot)
y_approx = lagval(x_plot, c)


plt.plot(x_plot, y_plot, label='f(x)')
plt.plot(x_plot, y_approx, label='Approximation')
plt.legend()
plt.show()
