#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <cmath>

int main() {
    int h, w;
    std::cin >> h >> w;

    std::uint64_t mx = std::pow(10, 9) + 7;

    std::vector<std::vector<bool>> field(h, std::vector<bool>(w));
    for(int i = 0; i < h; i++) {
        std::string s;
        std::cin >> s;
        std::transform(s.begin(), s.end(), field[i].begin(), [](auto c) {
            return c == '.';
        });
    }

    std::vector<std::vector<std::uint64_t>> dp(h, std::vector<std::uint64_t>(w, 0));
    dp[0][0] = 1;
    for(int j = 0; j < h; j++) {
        for(int i = 0; i < w; i++) {
            if(!field[j][i]) continue;
            if(i - 1 >= 0) {
                dp[j][i] += dp[j][i - 1];
            }
            if(j - 1 >= 0) {
                dp[j][i] += dp[j - 1][i];
            }
            if(dp[j][i] >= mx) {
                dp[j][i] %= mx;
            }
        }
    }
    std::cout << dp[h - 1][w - 1] << std::endl;
}