#include <cmath>
#include <iostream>
#include <vector>

#define N 1000

void thomas_algorithm(const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, const std::vector<double>& d, std::vector<double>& f) {
    std::vector<double> beta(N+1, 0.);
    std::vector<double> gama(N+1, 0.);

    beta[0] = -c[0] / b[0];
    gama[0] = -1. / b[0];

    for (int i = 1; i <= N; i++) {
        double n = 1. / (b[i] + a[i] * beta[i-1]);
        beta[i] = -c[i] * n;
        gama[i] = (d[i] - (a[i] * gama[i-1])) * n;
    }

    f[0] = 1;
    f[N] = -1;

    for (int i = (N - 1); i > 0; i--) {
        f[i] = gama[i] + beta[i] * f[i+1];
    }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
    double h = 0.01;

    std::vector<double> a(N+1);
    std::vector<double> b(N+1);
    std::vector<double> c(N+1);
    std::vector<double> d(N+1, 0.);
    std::vector<double> f(N+1);

    int i = 0;
    while (i < N) {
        a[i] = c[i] = 1./ (h*h);
        b[i] = (-2./ (h*h)) + 1.;
        i++;
    }

    a[0] = 0.; a[N] = 1.;
    b[0] = 1.; b[N] = -2.;
    c[0] = 0.; c[N] = 1.;

    thomas_algorithm(a, b, c, d, f);

    for (int i_ = 1; i_ < N; i_++) {
        std::cout << i_ * h << ". " << f[i_] << std::endl;
    }

    return 0;
}
