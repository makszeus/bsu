#include <climits>
#include <iostream>
#include <vector>

int func(const std::vector<std::vector<int>>& v, const int &n, const int &m) {

    std::vector<int> prev(m, INT_MAX), curr(m, INT_MAX);
    for (int j = 0; j < m; ++j) {
        prev[j] = v[0][j];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            curr[j] = INT_MAX;
            if (j > 0) {
                curr[j] = std::min(curr[j], prev[j - 1] + v[i][j]);
            }
            curr[j] = std::min(curr[j], prev[j] + v[i][j]);
            if (j < m - 1) {
                curr[j] = std::min(curr[j], prev[j + 1] + v[i][j]);
            }
        }
        prev = curr;
    }

    return *min_element(prev.begin(), prev.end());
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector A(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> A[i][j];
        }
    }
    std::cout << func(A, n, m) << std::endl;
    return 0;
}