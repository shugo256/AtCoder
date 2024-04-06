#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int n, k;
    ll x;
    std::cin >> n >> k >> x;
    
    std::vector<ll> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
        ll couponCount = std::min(ai / x, ll(k));
        ai -= x * couponCount;
        k -= couponCount;
    }
    ll ans = 0;
    std::sort(a.begin(), a.end(), std::greater<ll>());
    for (auto &ai : a) {
        if (k) {
            k--;
        } else {
            ans += ai;
        }
    }
    std::cout << ans << '\n';
    return 0;
}