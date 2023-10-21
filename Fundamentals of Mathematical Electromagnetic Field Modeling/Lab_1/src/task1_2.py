now = int(input())
a = 1
b = 0
index = 0

while now != b:
    a = a + b
    b = a - b
    index += 1
    if now < b:
        index = -1
        break

if index == 1: print(1, 2) # Единица в ряду чисел Фибоначчи встречается два раза
else: print(index)
