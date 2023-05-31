#include <algorithm>
#include <cstdint>
#include <iostream>
#include <type_traits>
#include <vector>

using item_t = std::pair<std::int64_t, std::int64_t>;

constexpr static std::int64_t inf = 1e9;

int main() {
    std::int64_t n, w;
    std::cin >> n >> w;

    // std::cout << n << " " << w << std::endl;
    std::vector<item_t> items(n);
    for(auto& [ww, v] : items) {
        std::cin >> ww >> v;
    }

    std::vector<std::vector<std::int64_t>> dp(n + 1, std::vector<std::int64_t>(w + 1, -inf));

    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        auto [w1, v1] = items[i];
        for(std::int64_t w_ = 0; w_ <= w; w_++) {
            if(w_ + w1 <= w) {
                dp[i + 1][w_ + w1] = std::max(dp[i][w_] + v1, dp[i + 1][w_ + w1]);
            } 
            dp[i + 1][w_] = std::max(dp[i][w_], dp[i + 1][w_]);
        }
    }
    
    std::vector<std::int64_t> max_list(n + 1);
    std::transform(dp.begin(), dp.end(), 
        max_list.begin(), [](auto v) { return *std::max_element(v.begin(), v.end()); });
    std::cout << *std::max_element(max_list.begin(), max_list.end()) << std::endl;
}