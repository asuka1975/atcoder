#include <iostream>
#include <vector>

constexpr static long long inf = 1e9;



int main() {
    long long n;
    std::cin >> n;
    std::vector<long long> hs(n);
    for(auto& h : hs) std::cin >> h;


    std::vector<long long> v(n, inf);
    v[0] = 0;


    for(long long i = 0; i < n; i++) {
        if(i + 1 < n) {
            v[i + 1] = std::min(v[i + 1], v[i] + std::abs(hs[i] - hs[i + 1]));
        }
        if(i + 2 < n) {
            v[i + 2] = std::min(v[i + 2], v[i] + std::abs(hs[i] - hs[i + 2]));
        }
    }

    std::cout << v[n - 1] << std::endl;

}