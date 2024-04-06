#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        ll n;
        std::cin >> n;
        if (n % 4 == 0) {
            std::cout << "Even" << '\n';
        } else if (n % 2 == 0) {
            std::cout << "Same" << '\n';
        } else {
            std::cout << "Odd" << '\n';
        }
    }
    return 0;
}