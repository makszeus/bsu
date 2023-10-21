# Задание 3.

import numpy as np

def compute_sum_of_cubes(filename):
    matrix = np.loadtxt(filename)
    second_column = matrix[:, 1]  # Извлекаем второй столбец матрицы
    filtered_elements = second_column[(second_column > 2) & (second_column < 10)]  # Применяем условие фильтрации

    sum_of_cubes = np.sum(filtered_elements ** 3)  # Вычисляем сумму кубов отфильтрованных элементов
    return sum_of_cubes

result = compute_sum_of_cubes('matrix_C.txt')
print(result)
