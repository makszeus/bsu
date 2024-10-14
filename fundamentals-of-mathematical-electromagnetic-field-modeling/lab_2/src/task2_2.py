import random

lst = [random.randint(10, 50) for i in range(15)]
print("Исходный список:", lst)

min_val = min(lst)
min_idxs = [i for i, x in enumerate(lst) if x == min_val]
print("Минимальное значение списка:", min_val)
print("Индексы минимальных элементов списка:", min_idxs)
