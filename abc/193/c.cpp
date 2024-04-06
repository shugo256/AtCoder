#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

#define MAX 100001

int main() {
    ll n;
    std::cin >> n;
    std::vector<bool> used(MAX, false);
    ll sum = 0;
    for (ll a=2; a*a<=n; a++) {
        if (used[a]) continue;
        ll cnt = 0;
        ll base = a * a;
        for ( ; base <= n; base *= a, cnt++) {
            if (base < MAX) {
                used[base] = true;
            }
        }
        sum += cnt;
    }
    std::cout << n - sum << '\n';
    return 0;
}