#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    for ( ; a >= 0 && b >= 0; c ^= 1) {
        if (c) b--;
        else a--;
    }
    std::cout << (c ? "Aoki" : "Takahashi") << '\n';
    return 0;
}