#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <numeric>
#include <bitset>
#include <set>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;
using BS = std::bitset<16>;

int main() {
    int h, w, a, b;
    std::cin >> h >> w >> a >> b;
    int n = h * w;

    std::vector dp(1 << n, 0ll);
    dp[0] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int d = i * w + j;
            for (int k = 0; k < (1 << n); k++) {
                if (dp[k] == 0) continue;

                auto bs = BS(k);
                if (!bs[d] && (j < w - 1 && !bs[d+1])) {
                    // std::cerr << bs << ' ' << d << ' ' << d+1  << std::endl;
                    bs.set(d); bs.set(d+1);
                    dp[bs.to_ulong()] += dp[k];
                }
                bs = BS(k);
                if (!bs[d] && (i < h - 1 && !bs[d+w])) {
                    // std::cerr << bs << ' ' << d << ' ' << d+w  << std::endl;
                    bs.set(d); bs.set(d+w);
                    dp[bs.to_ulong()] += dp[k];
                }
            }
        }
    }

    ll ans = 0;
    for (int i=0; i<(1 << n); i++) {
        if (BS(i).count() == a * 2) {
            // std::cerr << BS(i) << ' ' << dp[i] << std::endl;
            ans += dp[i];
        }
    }
    std::cout << ans << '\n';
    return 0;
}