#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define maxi(a, b) a = max(a, b)

int main() {
    int n, t;
    cin >> n >> t;
    long a[n], b[n];
    for (int i=0; i<n; i++) cin >> a[i] >> b[i];
    long dp[n+1][t+1][2];
    fill(dp[0][0], dp[n+1][0], 0);
    for (int i=0; i<n; i++) {
        for (int j=0; j<t; j++) {
            if (j + a[i] <= t) {
                maxi(dp[i+1][j+a[i]][0], dp[i][j][0] + b[i]);
                maxi(dp[i+1][j+a[i]][1], dp[i][j][1] + b[i]);
            }
            maxi(dp[i+1][j][0], dp[i][j][0]);
            maxi(dp[i+1][j][1], dp[i][j][1]);
            maxi(dp[i+1][j][1], dp[i][j][0] + b[i]);
            // cerr << dp[i][j][0] << ' ' <<  dp[i][j][1] << '\n';
        }
    }
    long ans = 0;
    dp[n][t][1] = 0;
    for (auto &dpi:dp[n]) {
        ans = max({ans, dpi[0], dpi[1]});
    }
    cout << ans << '\n';
    return 0;
}