# Problem 3. Проход из первой строки в n-ную.

_Input file name: input.txt_</br>
_Output file name: output.txt_</br>
_Time limit: 1s_</br>
_Memory limit_</br>

Задана матрица $A$ натуральных чисел из $n$ строк и $m$ столбцов. За каждый проход через клетку с индексами $(i, j)$ взимается штраф $A_{i, j}$. Необходимо с минимальным штрафом пройти из какой-либо клетки 1-й строки в $n$-ную строку, при этом из текущей клетки $(i, j)$ можно перейти в любую из трёх соседних, стоящих в строке с номером, на единицу большим: $(i + 1, j − 1), (i + 1, j), (i + 1, j + 1)$ (если они существуют).

## Input
Первая строка содержит размеры матрицы $n$ и $m$ $(2 ≤ n ≤ 200, 1 ≤ m ≤ 1000)$. Следующие $n$ строк содержат элементы матрицы $A$ штрафов по строкам, в строке числа разделяются пробелами (все числа натуральные и не превосходят $10^6$).

## Output
Выведите одно число — минимальный штраф.

## Example

|input.txt|output.txt|
|---------|----------|
|2 2      |3         |
|1 1      |          |
|2 3      |          |