#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    ll k;
    std::cin >> k;
    ll ans = 0;
    for (ll a = 1; a <= k; a++) {
        for (ll b = 1; a * b <= k; b++) {
            ans += k / (a * b);
        }
    }
    std::cout << ans << '\n';
    return 0;
}