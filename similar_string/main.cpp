#include <iostream>
#include <string>

bool similar(char c1, char c2) {
    return c1 == c2 
        || ((c1 == '1' && c2 == 'l') || (c1 == 'l' && c2 == '1')) 
        || ((c1 == '0' && c2 == 'o') || (c1 == 'o' && c2 == '0'));
}
bool similar(const std::string& s1, std::string& s2) {
    for(std::size_t i = 0; i < s1.length(); i++) {
        if(!similar(s1[i], s2[i])) return false;
    }
    return true;
}

int main() {
    int n;
    std::string s, t;
    std::cin >> n >> s >> t;
    if(similar(s, t)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}