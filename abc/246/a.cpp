#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int x = 0, y = 0;
    for (int i = 0, xi, yi; i<3; i++) {
        std::cin >> xi >> yi;
        x ^= xi;
        y ^= yi;
    }
    std::cout << x << ' ' << y << '\n';
    return 0;
}