#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<double>> cholesky(std::vector<std::vector<double>> A) {
    int n = A.size();

    // Инициализация матрицы L
    std::vector<std::vector<double>> L(n, std::vector<double>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;

            // Сумма произведений L(k, i) и L(k, j)
            if (j == i) {
                for (int k = 0; k < j; k++)
                    sum += pow(L[j][k], 2);
                L[j][j] = sqrt(A[j][j] - sum);
            } else {
                for (int k = 0; k < j; k++)
                    sum += (L[i][k] * L[j][k]);
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }

    return L;
}

int main() {
    std::vector<std::vector<double>> A = {{4, 12, -16}, {12, 37, -43}, {-16, -43, 98}};
    std::vector<std::vector<double>> L = cholesky(A);

    for (int i = 0; i < L.size(); i++) {
        for (int j = 0; j < L[i].size(); j++) {
            std::cout << L[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}

