#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define INF 1000000000000000000
#define minimize(a, b) a = min(a, b)

int main() {
    int n, k;
    cin >> n >> k;
    vector<long> h(n+1);
    h[0] = 0;
    for (int i=1; i<=n; i++) cin >> h[i];
    h.push_back(0);
    long dp[n+2][k+1];
    fill(dp[0], dp[n+2], INF);
    dp[0][0] = 0;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=k; j++) {
            for (int l=0; i+l+1<=n+1 && j+l<=k; l++) { 
                minimize(dp[i+l+1][j+l], dp[i][j] + max(h[i+l+1] - h[i], 0l));
            }
            //cerr << dp[i][j] << ' ';
        }
        //cerr << '\n';
    }
    long ans = INF;
    for (auto &dpi:dp[n+1]) {
        ans = min(ans, dpi);
        // cerr << dpi << ' ';
    }
    // cerr << '\n';
    cout << ans << '\n';
    return 0;
}