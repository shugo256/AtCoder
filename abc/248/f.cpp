#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/modint>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;
using modint = atcoder::modint;

int main() {
    int n, p;
    std::cin >> n >> p;
    modint::set_mod(p);
    std::vector dp(n*2, std::vector(n, std::vector(2, modint(0))));

    dp[0][0][1] = 1;

    for (int i = 0; i < n*2 - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2 == 0) {
                // 縦
                dp[i+1][j][0] += dp[i][j][0] + dp[i][j][1];
                if (j < n - 1) {
                    dp[i+1][j+1][0] += dp[i][j][0];
                    dp[i+1][j+1][1] += dp[i][j][1];
                }
            } else {
                // 横
                dp[i+1][j][0] += dp[i][j][0];
                dp[i+1][j][1] += dp[i][j][1];
                if (j < n - 1) {
                    dp[i+1][j+1][1] += dp[i][j][0] * 2;
                }
            }
            // std::cerr << i << ' ' << j << ' ' << dp[i][j][0].val() << ' ' << dp[i][j][1].val() << std::endl;
        }
    }
    
    for (int i = 1; i < n; i++) {
        std::cout << dp[n*2-1][i][0].val() << ' ';
    }
    std::cout << '\n';
    return 0;
}