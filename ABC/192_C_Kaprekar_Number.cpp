#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    ll n; int k;
    std::cin >> n >> k;
    for (int i=0; i<k; i++) {
        std::string ns = std::to_string(n);
        std::sort(ns.begin(), ns.end());
        ll g2 = std::stoll(ns);
        std::reverse(ns.begin(), ns.end());
        ll g1 = std::stoll(ns);
        n = g1 - g2;
    }
    std::cout << n << '\n';
    return 0;
}