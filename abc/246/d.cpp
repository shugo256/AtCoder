#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

ll f(ll a, ll b) {
    return (a + b) * (a * a + b * b);
}

int main() {
    ll n;
    std::cin >> n;
    ll x = ll(1e18);

    for (ll a = 0, b = ll(std::cbrt(n)) + 1; a * a * a <= n; a++) {
        for ( ; f(a, b) >= n && b >= 0; amin(x, f(a, b)), b--);
    }
    std::cout << x << '\n';
    return 0;
}