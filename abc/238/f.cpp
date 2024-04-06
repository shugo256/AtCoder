#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/modint>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;
using modint = atcoder::modint998244353;

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> p(n);
    for (auto &pi : p) {
        std::cin >> pi;
        pi--;
    }
    std::vector<int> a(n);
    for (int i = 0, qi; i < n; i++) {
        std::cin >> qi;
        a[p[i]] = qi - 1;
    }
    
    std::vector dp(n + 1, std::vector(k + 1, std::vector(n + 1, modint(0))));
    dp[0][0][n] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= n; l++) {
                if (j < k && l >= a[i]) {
                    dp[i+1][j+1][l] += dp[i][j][l];
                }
                dp[i+1][j][std::min(a[i], l)] += dp[i][j][l];
            }
        }
    }
    std::cout << std::accumulate(dp[n][k].begin(), dp[n][k].end(), modint(0)).val() << '\n';
    return 0;
}