#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double** multiplyMatrix(double **A, double **B, int m, int n, int q) {
    auto **C = new double*[m];
    for (int i = 0; i < m; i++) {
        C[i] = new double[q];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][j] * B[k][j];
            }
        }
    }
    return C;
}

double* multiplyMatrixByVector(double** A, const double* B, int m, int n) {
    auto* C = new double[m];
    for (int i = 0; i < m; i++) {
        C[i] = 0;
        for (int k = 0; k < n; k++) {
            C[i] += A[i][0] * B[k];
            cout << C[i] << endl;
        }
    }
    return C;
}

double** multiplyVectors(double* A, double* B, int N) {
    auto** C = new double*[N];
    for (int i = 0; i < N; i++) {
        C[i] = new double[N];
    }
    return C;
}

bool is_TopLeft(double** A, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; i++) {
            if (A[i][j] != 0) return false;
        }
    }
    return true;
}

bool is_TopRight(double** A, int N) {
    for (int i = 1; i < N; i++) {
        for (int j = N - i; j < N; j++) {
            if (A[i][j] != 0) return false;
            cout << "TopRight" << endl;
            cout << A[i][j] << endl;
        }
    }
    return true;
}

bool is_Top(double** A, int N) {
    return is_TopLeft(A, N) || is_TopRight(A, N);
}

double norm(const double* v, int m) {
    int scalar_mult = 0;
    for (int i = 0; i < m; i++) {
        scalar_mult += v[i] * v[i];
    }
    return sqrt(scalar_mult);
}

double* substractVectors(const double* v, const double* e, int m) {
    auto* u = new double[m];
    for (int i = 0; i < m; i++) {
        u[i] = v[i] - e[i];
    }
    return u;
}

double** substractMatrix(double** U, double** V, int n) {
    auto** C = new double*[n];
    for (int i = 0; i < n; i++) {
        C[i] = new double[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = U[i][j] - V[i][j];
        }
    }
    return C;
}

double* multiplyVectorByNumber(const double* v, double n, int m) {
    auto* c = new double[m];
    for (int i = 0; i < m; i++) {
        c[i] = v[i] * n;
    }
    return c;
}

double** multiplyMatrixByNumber(double** V, double n, int m) {
    auto** C = new double*[m];
    for (int i = 0; i < m; i++) {
        C[i] = new double[m];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = V[i][j] * n;
        }
    }
    return C;
}

double** formP(double** P, int m, int N) {
    auto** P1 = new double*[N];
    for (int i = 0; i < N; i++) {
        P1[i] = new double[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) P1[i][j] = 1;
            else P1[i][j] = 0;
        }
    }
    for (int i = N - m; i < N; i++) {
        for (int j = N - m; j < N; j++) {
            P1[i][j] = P[i - N + m][j - N + m];
        }
    }
    return P1;
}

int main() {
    ifstream f1("matrix.txt");
    int N = 0;
    f1 >> N;
    auto** A = new double*[N];
    for (int i = 0; i < N; i++) {
        A[i] = new double[N];
    }
    auto* B = new double[N];
    int i = 0;
    int j = 0;
    while (i < N) {
        while (j < N) {
            if (f1 >> A[i][j]) {
                j++;
            }
        }
        j = 0;
        i++;
    }
    i = 0;
    j = 0;
    while (i < N) {
        if (f1 >> B[i]) {
            i++;
        }
    }
    double* u;
    i = 0;
    int m = N;
    while (!is_Top(A, N)) {
        auto** E = new double*[m];
        for (int i_ = 0; i_ < m; i_++) {
            E[i_] = new double[m];
        }
        for (int i_ = 0; i_ < m; i_++) {
            for (int j_ = 0; j_ < m; j_++) {
                if (i_ == j_) E[i_][j_] = 1;
                else E[i_][j_] = 0;
            }
        }
        auto* v = new double[m];
        u = new double[m];
        for (int j_ = i; j_ < m; j_++) {
            v[j_] = A[i][j_];
        }
        auto* e = new double[m];
        e[0] = 1;
        for (int k = 1; k < m; k++) {
            e[k] = 0;
        }
        int sigma = 1;
        if (v[0] >= 0) sigma = -1;
        double ch = sigma * norm(v, m);
        u = substractVectors(v, multiplyVectorByNumber(e, ch, m), m);
        double** K = multiplyMatrixByNumber(multiplyVectors(u, u, m), 2 / norm(u, m) * norm(u, m), m);
        K = substractMatrix(E, K, m);
        K = formP(K, m, N);
        A = multiplyMatrix(A, K, N, N, N);
        i++;
        m--;
    }
    auto* X = new double[N];
    for (int k = N - 1; k >= 0; k--) {
        double d = 0;
        for (int j_ = k + 1; j_ < N; j_++) {
            double s = A[k][j_] * X[j_];
            d = d + s;
        }
        X[k] = (B[k] - d) / A[k][k];
    }
    for (i = 0; i < N; i++) {
        cout << X[i] << endl;
    }
    f1.close();
    for (int i_ = 0; i_ < N; i_++) {
        delete[] A[i_];
    }
    delete[] u;
    delete[] A;
    delete[] B;
    delete[] X;
    return 0;
}
