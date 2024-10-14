# Задание 2.

import numpy as np
import time

def compute_sum_with_loops(z, N=10):
    if z <= 0 or z >= N+1:
        print("Ошибка: аргумент z вне области сходимости ряда")
        return
    
    total_sum = 0.0
    
    for k in range(1, N+1):
        element = k / 3 * np.log(1 + z / k)
        total_sum += element
    
    return total_sum


def compute_sum_without_loops(z, N=10):
    if z <= 0 or z >= N+1:
        print("Ошибка: аргумент z вне области сходимости ряда")
        return
    
    k_values = np.arange(1, N+1)
    elements = k_values / 3 * np.log(1 + z / k_values)
    total_sum = np.sum(elements)
    
    return total_sum


# Пример использования функций и сравнение времени выполнения
z = 5
N = 1000000

start_time = time.time()
result_with_loops = compute_sum_with_loops(z, N)
end_time = time.time()
execution_time_with_loops = end_time - start_time

start_time = time.time()
result_without_loops = compute_sum_without_loops(z, N)
end_time = time.time()
execution_time_without_loops = end_time - start_time

print("Сумма (с использованием циклов):", '{:.3f}'.format(result_with_loops))
print("Время выполнения (с использованием циклов):", '{:.3f}'.format(execution_time_with_loops), "с")

print("Сумма (без использования циклов):", '{:.3f}'.format(result_without_loops))
print("Время выполнения (без использования циклов):", '{:.3f}'.format(execution_time_without_loops), "с")
