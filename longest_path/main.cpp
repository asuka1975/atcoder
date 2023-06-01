#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <list>

using edge = std::pair<int, int>;
using path = std::list<edge>;

int main() {
    int n, m;
    std::cin >> n >> m;


    std::vector<edge> graph(m);
    for(auto& [s, t] : graph) {
        std::cin >> s >> t;
    }

    std::map<edge, std::vector<path>> dp;

    for(auto e : graph) {
        dp[e].resize(2);
        dp[e][0].push_back(e);
    }
    

    for(int i = 0; i < m; i++) {
        auto e1 = graph[i];
        for(int k = 0; k < m; k++) {
            auto j = k % 2;
            auto e2 = graph[k];
            if(e1.second == e2.first) {
                auto& p2 = dp[e2][1 - j];
                auto p1 = dp[e1][j];
                p1.push_back(e2);
                if(p1.size() > p2.size()) {
                    p2 = p1;
                }
            }

            auto& p2 = dp[e1][1 - j];
            auto& p1 = dp[e1][j];
            if(p1.size() > p2.size()) {
                p2 = p1;
            }
        }
    }

    std::cout << std::max_element(dp.begin(), dp.end(), [m](auto a, auto b) {
        return a.second[1 - m % 2].size() < b.second[1 - m % 2].size();
    })->second[1 - m % 2].size() << std::endl;
}