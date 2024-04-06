#include <iostream>
#include <algorithm>

#define INF 1000000000000000

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long dp[n+1][2];
    fill(dp[0], dp[n+1], -INF);
    dp[0][0] = 0;
    for (int i=0; i<n; i++) {
        long b; cin >> b;
        dp[i+1][0] = max(dp[i+1][0], max(dp[i][0], dp[i][1]) + b);
        dp[i+1][1] = max(dp[i+1][1], dp[i][1]);
        if (i+k <= n) {
            dp[i+k][0] = max(dp[i+k][0], dp[i][0]);
            dp[i+k][1] = max(dp[i+k][0], dp[i][0]);
        }
        //cerr << dp[i+1][0] << ' ' << dp[i+1][1] << '\n';
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
    return 0;
}