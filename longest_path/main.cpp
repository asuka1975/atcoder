#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <set>

using edge = std::pair<int, int>;
using path = std::list<edge>;

void DFS(const std::unordered_map<int, std::set<int>>& graph, int from, std::vector<bool>& visited, std::vector<int>& result)
{
	visited[from] = true;

	for (const auto& to : graph.at(from))
	{
		if (!visited[to])
		{
			DFS(graph, to, visited, result);
		}
	}

	// 帰りがけ順
	result.push_back(from);
}

/// @brief トポロジカルソート
/// @param graph グラフ
/// @remark グラフは有向非巡回グラフ (DAG) でなければならない
/// @return トポロジカルソートの結果
/// @note 1.1 深さ優先探索を用いたトポロジカルソート
/// @see https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/topological-sort
std::vector<int> TopologicalSort(const std::unordered_map<int, std::set<int>>& graph)
{
	std::vector<int> result;

	std::vector<bool> visited(graph.size());

	for (int i = 1; i <= static_cast<int>(graph.size()); ++i)
	{
		if (!visited[i])
		{
			DFS(graph, i, visited, result);
		}
	}

	std::reverse(result.begin(), result.end());

	return result;
}

int main() {
    int n, m;
    std::cin >> n >> m;




    std::unordered_map<int, std::set<int>> graph;
    for(int i = 1; i <= n; i++) {
        graph[i];
    }

    for(int i = 0; i < m; i++) {
        int in, out;
        std::cin >> in >> out;
        graph[in].insert(out);
    }

    auto L = TopologicalSort(graph);
    
    std::map<int, int> dp;

    for(int i = 1; i <= n; i++) {
        dp[i] = 0;
    }


    for(auto m : L) {
        const auto& e = graph[m];
        for(auto j : e) {
            if(dp[j] < dp[m] + 1) {
                dp[j] = dp[m] + 1;
            }
        }
    }

    // for(auto& [n, v] : dp) {
    //     std::cout << n << ": ";
    //     for(auto x : v) {
    //         std::cout << x << " ";
    //     }
    //     std::cout << std::endl;
    // }

    std::cout << std::max_element(dp.begin(), dp.end(), [&L](auto a, auto b) {
        return a.second < b.second;
    })->second << std::endl;
}