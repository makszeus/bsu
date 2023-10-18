import numpy as np
import matplotlib.pyplot as plt

t = np.linspace(-3*np.pi/8, 3*np.pi/8, 100)
x = np.tan(t)
y = np.cos(t)**2

plt.plot(x, y)
plt.grid(True)
plt.xlabel('x')
plt.ylabel('y')
plt.title('Verzier Aniezzi Curve')

plt.show()
