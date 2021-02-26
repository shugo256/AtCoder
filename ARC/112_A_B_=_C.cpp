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
        int l, r;
        std::cin >> l >> r;
        ll d = std::max(r - 2*l + 1, 0);
        std::cout << d * (d + 1) / 2 << '\n';
    }
    return 0;
}