# Задание 1.

import numpy as np

# Определение матрицы A
A = np.diag(np.arange(1, 14, 2)) + np.diag(2 * np.ones(6), k=1)
A[-1, :] = -8

# Находим собственные значения и собственные векторы
eigenvalues, eigenvectors = np.linalg.eig(A)

# Выводим результаты
print("Собственные значения:")
np.set_printoptions(precision=3)
print(eigenvalues)
print("\nСобственные векторы:")
print(eigenvectors)

# Выбираем наименьшее по модулю собственное значение
smallest_eigenvalue = min(abs(eigenvalues))

# Индекс наименьшего по модулю собственного значения
index = np.where(abs(eigenvalues) == smallest_eigenvalue)[0][0]

# Собственный вектор для наименьшего по модулю собственного значения
eigenvector = eigenvectors[:, index]

# Проверяем равенство Ax = yx
result = np.allclose(np.dot(A, eigenvector), smallest_eigenvalue * eigenvector)

# Выводим результат
print("\nРавенство Ax = yx для наименьшего по модулю собственного значения:")
print(result)
