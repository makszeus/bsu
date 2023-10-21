# 2. Напишите программу, в которой на основе двух словарей создается новый словарь. В этот новый словарь включатся те элементы, которые представлены в каждом из исходных словарей (имеются в виду ключи элементов). Значениями элементов в создаваемом словаре являются множества из значений соответствующих элементов в исходных словарях.

def intersect_dictionaries(dict1, dict2):
    intersection = {key: set(dict1[key]) & set(dict2[key]) for key in dict1.keys() & dict2.keys()}
    return intersection

dict1 = {'a': [1, 2, 3], 'b': [4, 5, 6]}
dict2 = {'a': [2, 3, 4], 'c': [7, 8, 9]}
new_dict = intersect_dictionaries(dict1, dict2)
print(new_dict)
