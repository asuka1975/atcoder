#include <iostream>
#include <cstdint>
#include <vector>

struct item {
    std::int64_t l;
    std::int64_t r;
    std::int64_t a;
};



int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<item> items(M);
    for(auto& [l, r, a] : items) {
        std::cin >> l >> r >> a;
    }

    
}