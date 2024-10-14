import numpy as np
import matplotlib.pyplot as plt

def y(t):
    return t * np.log(t) + (1 + t**2 * np.sin(t))**(1/4)

def z(t):
    return (1 + t**4) / (1 + t**2)**(1/4)

def w(t):
    return z(t) - y(t)

t = np.linspace(0.1, 10, 100)  # Adjust the range as needed

plt.plot(t, y(t), 'r-', label='y(t)')
plt.plot(t, z(t), 'g--', label='z(t)')
plt.plot(t, w(t), 'b:', label='w(t)')

plt.legend()
plt.show()
