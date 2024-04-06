#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    std::string x;
    std::cin >> x;
    for (auto &c:x) {
        if (c == '.') break;
        std::cout << c;
    }
    std::cout << '\n';
    return 0;
}