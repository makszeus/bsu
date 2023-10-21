# Лабораторная работа 3
# Задание 1. Определить, сколько раз в тексте встречается заданное слово

import re

def count_word_occurrences(text, word):
    cleaned_text = re.sub(r'[^\w\s]', '', text.lower())
    occurrences = len(re.findall(r'\b{}\b'.format(re.escape(word.lower())), cleaned_text))
    return occurrences

text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis viverra, ipsum in " \
       "scelerisque sodales, mi sapien eleifend erat, vel varius mauris mauris vitae " \
       "tortor. Sed condimentum sem vitae orci ullamcorper, a pellentesque tellus " \
       "fermentum. Nullam eleifend erat eu est finibus gravida. Morbi nec lacus id " \
       "mauris molestie maximus. Curabitur tincidunt ullamcorper imperdiet. Ut " \
       "aliquet suscipit porta. Sed non faucibus nibh. Pellentesque pharetra ligula " \
       "quis tristique pellentesque. Sed bibendum maximus aliquet."

word = "aliquet"

occurrences = count_word_occurrences(text, word)
print(f"Слово '{word}' встречается {occurrences} раз(а) в тексте.")
