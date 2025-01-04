#include <iostream>
#include <vector>

int getSum(const std::vector<int>& prefixSum, const int &i, const int &j) {
    return prefixSum[j + 1] - prefixSum[i];
}

int tape (const int &n, const std::vector<int> &v) {
    std::vector dp(n, std::vector(n, 0));
    std::vector sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + v[i];
    }

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            if (int j = i + len - 1; i == j) {
                dp[i][j] = v[i];
            } else {
                dp[i][j] = std::max(
                    v[i] + getSum(sum, i + 1, j) - dp[i + 1][j],
                    v[j] + getSum(sum, i, j - 1) - dp[i][j - 1]
                );
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    int n; std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    std::cout << tape(n, v);
    return 0;
}