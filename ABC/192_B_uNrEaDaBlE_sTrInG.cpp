#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    std::string s;
    std::cin >> s;
    for (int i=0; i<s.size(); i++) {
        if ((i % 2 == 0) ^ (s[i] >= 'a' && s[i] <= 'z')) {
            std::cout << "No" << '\n';
            return 0;
        }
    }
    std::cout << "Yes" << '\n';
    return 0;
}