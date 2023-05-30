#include <iostream>
#include <cstdint>
#include <vector>
#include <tuple>

constexpr static std::int64_t inf = -1e9;

using hapiness = std::tuple<std::int64_t, std::int64_t, std::int64_t>;

int main() {
    int n;
    std::cin >> n;

    std::vector<hapiness> hs(n);

    for(auto& [a, b, c] : hs) {
        std::cin >> a >> b >> c;
    }

    std::vector<std::vector<std::uint64_t>> dp(n + 1, std::vector<std::uint64_t>(3, 0));

    for(int i = 0; i < n; i++) {
        dp[i + 1][1] = std::max(dp[i + 1][1], dp[i][0] + std::get<1>(hs[i]));
        dp[i + 1][2] = std::max(dp[i + 1][2], dp[i][0] + std::get<2>(hs[i]));

        dp[i + 1][0] = std::max(dp[i + 1][0], dp[i][1] + std::get<0>(hs[i]));
        dp[i + 1][2] = std::max(dp[i + 1][2], dp[i][1] + std::get<2>(hs[i]));

        dp[i + 1][0] = std::max(dp[i + 1][0], dp[i][2] + std::get<0>(hs[i]));
        dp[i + 1][1] = std::max(dp[i + 1][1], dp[i][2] + std::get<1>(hs[i]));
    }

    std::cout << std::max(std::max(dp[n][0], dp[n][1]), dp[n][2]) << std::endl;
}