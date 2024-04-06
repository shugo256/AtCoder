#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/modint>
#include <numeric>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;
using modint = atcoder::modint998244353;

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector dp(n + 1, std::vector(k + 1, modint(0)));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int l = 1; l <= m && j + l <= k; l++) {
                dp[i+1][j + l] += dp[i][j];
            }
        }
    }
    std::cout << std::accumulate(dp[n].begin(), dp[n].end(), modint(0)).val() << '\n';
    return 0;
}