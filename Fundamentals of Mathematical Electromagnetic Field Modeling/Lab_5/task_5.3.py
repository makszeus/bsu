import numpy as np

def solve_linear_system(*args):
    if len(args) == 2:
        C = args[0]
        b = args[1]
    elif len(args) == 1:
        C = args[0]
        b = np.random.uniform(1, 3, size=C.shape[0]) # Формируем случайный вектор b

    # Проверка на вырожденность матрицы C
    if np.linalg.det(C) == 0:
        return None, None  # Если матрица вырожденная, возвращаем None

    # Решение системы уравнений
    x = np.linalg.solve(C, b)

    norm = np.linalg.norm(x, ord=1)  # октаэдрическая норма

    return x, norm


C = np.array([[1, 2], [3, 4]])
b = np.array([5, 6])

x, norm = solve_linear_system(C, b)
print("Решение системы:", x)
print("Норма:", norm)
