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

#define amin(a, b) a = min(a, b)
#define amax(a, b) a = max(a, b)

int main() {
    int n;
    ll t;
    cin >> n >> t;
    P shops[n];
    for (auto &si:shops) {
        cin >> si.fi >> si.se;
        si.fi++; si.se++;
    }
    sort(shops, shops+n);
    vector<ll> rui(1, 0);
    for (auto &si:shops) {
        if (si.fi > 1) break;
        rui.push_back(rui.back() + si.se);
    }
    vector<P> mul(shops+rui.size()-1, shops+n);
    sort(mul.begin(), mul.end(), [](P l, P r) {
        return l.se * (r.fi - 1) < (l.fi - 1) * r.se;
    });
    int m = mul.size();
    ll dp[m+1][30];
    fill(dp[0], dp[m+1], t+2);
    dp[0][0] = 1;
    for (int i=0; i<m; i++) {
        ll a = mul[i].fi, b = mul[i].se;
        for (int j=0; j<30; j++) {
            amin(dp[i+1][j+1], a * dp[i][j] + b);
            amin(dp[i+1][j], dp[i][j]);
        }
    }
    int ans = 0;
    for (int i=0; i<=m; i++) {
        for (int j=0; j<30; j++) {
            int x = partition_point(rui.begin(), rui.end(), [&](ll r) { return r + dp[i][j] - 1 <= t; }) - rui.begin();
            amax(ans, (x > 0 ? j + x - 1 : 0));
        }
    }
    cout << ans << '\n';
    return 0;
}