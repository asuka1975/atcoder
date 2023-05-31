#include <cstdint>
#include <iostream>
#include <vector>

using item_t = std::pair<std::int64_t, std::int64_t>;

constexpr static std::int64_t inf = 1e10;
constexpr static std::int64_t value_max = 100000;

/*
 * dp[i][j] := 品物を持つかどうかi回目のとき、価値の総和がjのときの重さの総和の最小値
 * 
 * dp[0][0] = 0
 *
 * dp[i][v] + wi <= W && v + vi <= 1000で
 * dp[i + 1][v + vi] = std::min(dp[i][v] + wi, dp[i + 1][v + vi]);
 *
 * そうでないとき
 * dp[i + 1][v] = std::min(dp[i][v], dp[i + 1][v]);
 */

int main() {
    int n, w;
    std::cin >> n >> w;

    std::vector<item_t> items(n);
    for(auto& [wi, vi] : items) {
        std::cin >> wi >> vi;
    }

    std::vector<std::vector<std::int64_t>> dp(n + 1, std::vector<std::int64_t>(value_max + 1, inf));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        auto [wi, vi] = items[i];

        for(std::int64_t v = 0; v <= value_max; v++) {
            if(dp[i][v] + wi <= w && v + vi <= value_max) {
                dp[i + 1][v + vi] = std::min(dp[i][v] + wi, dp[i + 1][v + vi]);
            }
            dp[i + 1][v] = std::min(dp[i][v], dp[i + 1][v]);
        }
    }

    auto& last = dp[n];
    for(auto i = value_max; i >= 0; i--) {
        if(last[i] != inf) {
            std::cout << i << std::endl;
            break;
        }
    }
}