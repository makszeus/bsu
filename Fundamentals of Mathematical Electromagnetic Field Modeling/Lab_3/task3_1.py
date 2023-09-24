# Лабораторная 3.
# 1. Определить, сколько раз в тексте встречается заданное слово

def count_word_occurrences(text, word):
    return text.lower().split().count(word.lower())

text = "Текст с заданным словом. Слово слово СЛОВА с с с с Словарь"
word = "слово"
occurrences = count_word_occurrences(text, word)
print(f"Слово '{word}' встречается {occurrences} раз(а) в тексте.")
