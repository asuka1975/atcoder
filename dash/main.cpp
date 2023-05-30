#include <iostream>
#include <string>
#include <vector>
#include <set>

using point = std::pair<int, int>;

void move(point& p, std::set<point>& items, int& h, int k, char c) {
    switch(c) {
        case 'R':
            p.first += 1;
            break;
        case 'L':
            p.first -=1;
            break;
        case 'U':
            p.second += 1;
            break;
        case 'D':
            p.second -= 1;
            break;
    }
    h--;
    if(h >= 0) {
        if(items.count(p) == 1 && h < k) {
            items.erase(p);
            h = k;
        }
    }
}

int main() {
    int n, m, h, k;
    std::string s;

    std::cin >> n >> m >> h >> k;
    std::cin >> s;

    point p;
    std::vector<point> moves_in(m);

    for(auto& [x, y] : moves_in) {
        std::cin >> x >> y;
    }

    std::set<point> moves(moves_in.begin(), moves_in.end());

    for(char m : s) {
        if(h < 0) break;
        move(p, moves, h, k, m);
    }

    if(h < 0) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }
}