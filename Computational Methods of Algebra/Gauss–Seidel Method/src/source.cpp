#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    double eps;
    std::cout << "Введите размер матрицы: ";
    std::cin >> n;
    std::cout << "Введите точность: ";
    std::cin >> eps;

    std::vector<std::vector<double>> a(n, std::vector<double>(n));
    std::vector<double> b(n);
    std::vector<double> x(n, 0.0);

    std::cout << "Введите коэффициенты матрицы и свободные члены:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
        }
        std::cin >> b[i];
    }

    bool converge = false;
    while (!converge) {
        converge = true;
        for (int i = 0; i < n; ++i) {
            double temp = b[i];
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    temp -= a[i][j] * x[j];
                }
            }
            temp /= a[i][i];
            if (std::abs(x[i] - temp) > eps) {
                converge = false;
            }
            x[i] = temp;
        }
    }

    std::cout << "Решение системы:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
    }

    return 0;
}

