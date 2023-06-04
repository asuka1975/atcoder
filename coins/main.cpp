#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<double> ps(n);

    for(auto& p : ps) {
        std::cin >> p;
    }

    std::vector<std::vector<double>> dp(n, std::vector<double>(n + 1, 0));

    dp[0][0] = 1 - ps[0];
    dp[0][1] = ps[0];

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j <= i + 1; j++) {
            dp[i + 1][j] += dp[i][j] * (1 - ps[i + 1]);
            dp[i + 1][j + 1] += dp[i][j] * ps[i + 1];
        }
    }

    double p = 0;
    for(int i = n / 2 + 1; i <= n; i++) {
        p += dp[n - 1][i];
    }

    std::cout << p << std::endl;
}