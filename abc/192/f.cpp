#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int n; ll x;
    std::cin >> n >> x;
    std::vector<ll> a(n);
    ll best = 0;
    for (auto &ai:a) {
        std::cin >> ai;
        amax(best, ai);
    }
    ll ans = x - best;
    for (int i=1; i<=n; i++) {
        std::vector dp(i+1, std::vector(i, -1ll));
        dp[0][0] = 0;
        for (int j=0; j<n; j++) {
            for (int k=i-1; k>=0; k--) {
                for (int l=0; l<i; l++) {
                    if (dp[k][l] < 0) continue;
                    amax(dp[k+1][(l+a[j]) % i], dp[k][l] + a[j]);
                }
            }
        }
        ll r = x % i;
        // std::cerr << i << ' ' << r << ' ' << dp[i][r] << std::endl;
        if (dp[i][r] >= 0)
            amin(ans, (x - dp[i][r]) / i);
    }
    std::cout << ans << '\n';
    return 0;
}