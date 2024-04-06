#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }

    if (a[n-1] > a[n-2] + 1) {
        std::cout << "Alice" << '\n';
        return 0;
    }

    std::cout << ((a[n-1] - n + 1) % 2 ? "Alice" : "Bob") << '\n';
    return 0;
}