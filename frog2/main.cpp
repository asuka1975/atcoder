#include <iostream>
#include <cstdint>
#include <vector>

constexpr static std::uint64_t inf = 1e9;

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> hs(n);
    for(auto& h : hs) std::cin >> h;

    std::vector<int> dp(n, inf);

    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            if(i + j < n) {
                dp[i + j] = std::min(dp[i + j], dp[i] + std::abs(hs[i] - hs[i + j]));
            }
        }
    }

    std::cout << dp[n - 1] << std::endl;
}