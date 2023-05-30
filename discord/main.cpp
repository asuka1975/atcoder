#include <iostream>
#include <utility>
#include <vector>
#include <set>

std::pair<int, int> gpair(int a, int b) {
    return std::make_pair(std::min(a, b), std::max(a, b));
}

std::set<std::pair<int, int>> create_combination(int N) {
    std::set<std::pair<int, int>> r;
    for(int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
            r.emplace(i, j);
        }
    }
    return std::move(r);
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> input(M);
    for(int i = 0; i < M; i++) {
        input[i].resize(N);
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> input[i][j];
        }
    }

    auto s = create_combination(N);

    for(int j = 0; j < M; j++) {
        for(int i = 0; i < N - 1; i++) {
            auto p = gpair(input[j][i], input[j][i + 1]);
            s.erase(p);
        }
    }
    std::cout << s.size() << std::endl;
}