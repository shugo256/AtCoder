#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <numeric>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int n;
    std::cin >> n;
    std::map<ll, ll> gcdSum;
    ll min = 1000000000ll;
    for (int i=0; i<n; i++) {
        ll ai;
        std::cin >> ai;
        amin(min, ai);
        for (ll x=1; x*x<=ai; x++) {
            if (ai % x == 0) {
                gcdSum[x] = std::gcd(gcdSum[x], ai);
                if (ai != x*x) {
                    gcdSum[ai / x] = std::gcd(gcdSum[ai / x], ai);
                }
            }
        }
    }
    int ans = 0;
    for (auto &[key, val]:gcdSum) {
        if (key > min) break;
        if (key == val) ans++;
    }
    std::cout << ans << '\n';
    return 0;
}