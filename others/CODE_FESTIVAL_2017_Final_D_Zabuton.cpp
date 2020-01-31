#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

using P = pair<ll, ll>;
#define fi first
#define se second

#define INF 10000000000000ll

int main() {
    int n;
    cin >> n;
    P part[n];
    for (auto &p:part) cin >> p.fi >> p.se;
    sort(part, part+n);
    ll dp[n+1];
    fill(dp, dp+n+1, INF);
    dp[0] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=n; j++) {
            if (dp[j] > part[i].fi) break;
            dp[j+1] = min(dp[j+1], dp[j] + part[i].se);
        }
    }
    int ans;
    for (int i=0; i<=n; i++) {
        if (dp[i] == INF) break;
        ans = i;
    }
    cout << ans << '\n';
    return 0;
}