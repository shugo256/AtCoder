#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <numeric>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    ll n;
    std::cin >> n;
    ll l = 1;
    for (ll i=2; i<=n; i++) {
        l = std::lcm(l, i);
    }
    std::cout << l + 1 << '\n';
    return 0;
}