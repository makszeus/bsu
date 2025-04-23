#include <iostream>
#include <vector>

void thomas_algorithm(const std::vector<double>& A,
                      const std::vector<double>& B,
                      const std::vector<double>& C,
                      const std::vector<double>& D,
                      std::vector<double>& X) {
    size_t N = D.size();
    std::vector<double> alpha(N);
    std::vector<double> beta(N);

    alpha[0] = -C[0] / B[0];
    beta[0]  =  D[0] / B[0];

    for (size_t i = 1; i < N; ++i) {
        double denom = B[i] + A[i] * alpha[i - 1];
        alpha[i] = (i == N - 1) ? 0.0 : -C[i] / denom;
        beta[i]  = (D[i] - A[i] * beta[i - 1]) / denom;
    }

    X[N - 1] = beta[N - 1];

    for (int i = N - 2; i >= 0; --i) {
        X[i] = alpha[i] * X[i + 1] + beta[i];
    }
}


int main() {

    // Example.
    // 2x_1 +  x_2        = 5
    //  x_1 + 3x_2 +  x_3 = 6
    //      + 2x_2 + 4x_3 = 7

    const std::vector<double> A = {0, 1, 2};
    const std::vector<double> B = {2, 3, 4};
    const std::vector<double> C = {1, 1, 0};
    const std::vector<double> D = {5, 6, 7};
    std::vector<double> X (3);

    thomas_algorithm(A, B, C, D, X);

    std::cout << "Solution:" << std::endl;
    for (int i = 0; i < X.size(); ++i) {
        std::cout << "x[" << i + 1 << "] = " << X[i] << std::endl;
    }

    return 0;
}