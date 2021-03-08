#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

bool check(ll x, ll y) {
    return (x + y) % 2 == 1;
}

int main() {
    ll n;
    std::cin >> n;
    ll n_2 = n * 2;
    ll ans = 0;
    for (ll i=1; i*i<=n_2; i++) {
        if (n_2 % i != 0) continue;
        ans += check(i, n_2 / i);
        ans += check(n_2 / i, i);
    }
    std::cout << ans << '\n';
    return 0;
}