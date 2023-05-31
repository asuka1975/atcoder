#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>


// dp[i][j] := sのi文字目まで見るかつ, tのj文字目までみる

struct fixed_string {
    char content[3001];
    int len = 0;

    fixed_string& operator+=(char c) {
        content[len++] = c;
        return *this;
    }

    int length() {
        return len;
    }
};

int main() {
    std::string s, t;
    std::cin >> s >> t;

    std::vector<std::vector<std::string>> dp(2, std::vector<std::string>(t.size() + 1));

    for(std::uint64_t k = 0; k < s.length(); k++) {
        auto i = k % 2;
        auto c1 = s[k];
        for(std::uint64_t j = 0; j < t.length(); j++) {
            auto c2 = t[j];
            if(c1 == c2) {
                if(dp[i][j].length() + 1 > dp[1 - i][j + 1].length()) {
                    dp[1 - i][j + 1] = dp[i][j] + c1;
                }
            }
            else {
                if(dp[i][j].length() > dp[1 - i][j + 1].length()) {
                    dp[1 - i][j + 1] = dp[i][j];
                }
                if(dp[1 - i][j + 1].length() < dp[1 - i][j].length()) {
                    dp[1 - i][j + 1] = dp[1 - i][j];
                }
                if(dp[1 - i][j + 1].length() < dp[i][j + 1].length()) {
                    dp[1 - i][j + 1] = dp[i][j + 1];
                }
            }
        }
    }


    std::cout << dp[s.length() % 2][t.length()] << std::endl;
}