import random

lst = [random.randint(0, 9) for i in range(10)]
print("Исходный список:", lst)

res_lst = [lst[i] for i in range(len(lst)-1) if lst[i] > lst[i+1]]
print(res_lst)
