# 3.Написать программу для вывода правильно отформатированного представления первых восьми строк треугольника Паскаля.

def pascal_triangle(n):
    triangle = [[1]]
    for _ in range(1, n):
        row = [1]
        prev_row = triangle[-1]
        for i in range(len(prev_row) - 1):
            row.append(prev_row[i] + prev_row[i + 1])
        row.append(1)
        triangle.append(row)
    return triangle

def format_pascal_triangle(triangle):
    max_element_length = len(str(max(triangle[-1])))
    formatted_triangle = ""
    for row in triangle:
        formatted_row = " ".join([str(element).center(max_element_length) for element in row])
        formatted_triangle += f"{formatted_row}\n"
    return formatted_triangle

triangle = pascal_triangle(8)
formatted_triangle = format_pascal_triangle(triangle)
print(formatted_triangle)
