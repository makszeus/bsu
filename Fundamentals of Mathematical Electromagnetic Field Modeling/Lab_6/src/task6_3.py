import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def z(x, y):
    return 2 * x**2 * np.cos(x)**2 - 5 * np.exp(2 * y)

x = np.linspace(-1, 1, 100)
y = np.linspace(-1, 1, 100)
X, Y = np.meshgrid(x, y)
Z = z(X, Y)

plt.figure()
plt.contour(X, Y, Z)
plt.xlabel('x')
plt.ylabel('y')
plt.title('Contour Plot of z(x, y)')
plt.colorbar()
plt.show()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, Y, Z, cmap='viridis')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('Surface Plot of z(x, y)')
plt.show()
