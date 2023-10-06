#include <iostream>
#include <iomanip>
#include <cmath>

const double EPSILON = 1e-10;

void printMatrix(double** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <= size; ++j) {
            std::cout << std::setw(10) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void solveSystem(double** matrix, int size, int precision) {
    // Прямой ход метода Гаусса
    for (int k = 0; k < size; ++k) {
        int maxRow = k;
        double maxElement = std::abs(matrix[k][k]);
        for (int i = k + 1; i < size; ++i) {
            if (std::abs(matrix[i][k]) > maxElement) {
                maxElement = std::abs(matrix[i][k]);
                maxRow = i;
            }
        }

        if (maxElement < EPSILON) {
            std::cout << "Система уравнений имеет бесконечное множество решений" << std::endl;
            return;
        }

        std::swap(matrix[k], matrix[maxRow]);

        for (int i = k + 1; i < size; ++i) {
            double factor = matrix[i][k] / matrix[k][k];
            for (int j = k; j <= size; ++j) {
                matrix[i][j] -= factor * matrix[k][j];
            }
        }
    }

    // Обратный ход метода Гаусса
    auto* solution = new double[size];
    for (int i = size - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < size; ++j) {
            sum += matrix[i][j] * solution[j];
        }
        solution[i] = (matrix[i][size] - sum) / matrix[i][i];
    }

    std::cout << "Решение системы:" << std::endl;
    std::cout << std::fixed << std::setprecision(precision);
    for (int i = 0; i < size; ++i) {
        std::cout << "x" << i << " = " << solution[i] << std::endl;
    }

    delete[] solution;
}

int main() {
    // Ввод размерности системы уравнений
    int size;
    std::cout << "Введите размерность системы уравнений: ";
    std::cin >> size;

    // Выделение памяти под матрицу системы
    auto** matrix = new double*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new double[size + 1];
    }

    // Ввод коэффициентов системы с клавиатуры
    std::cout << "Введите коэффициенты системы уравнений:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Уравнение " << i + 1 << ":" << std::endl;
        for (int j = 0; j <= size; ++j) {
            std::cout << "Коэффициент " << j + 1 << ": ";
            std::cin >> matrix[i][j];
        }
    }

    // Ввод количества знаков после запятой
    int precision;
    std::cout << "Введите количество знаков после запятой: ";
    std::cin >> precision;

    std::cout << "Исходная матрица:" << std::endl;
    printMatrix(matrix, size);

    solveSystem(matrix, size, precision);

    // Освобождение памяти
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
