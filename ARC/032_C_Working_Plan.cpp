#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define MAXT 1000002

using P = pair<int, int>;
#define fi first
#define se second

vector<P> sche[MAXT];
vector<P> jobs;
P dp[MAXT];

int main() {
    int n, maxt=0;
    cin >> n;
    for (int i=0, a, b; i<n; i++) {
        cin >> a >> b;
        jobs.push_back({a, b});
        sche[a].push_back({i, b});
        maxt = max(maxt, b);
    }
    fill(dp, dp+MAXT, P{0, 0}); // {仕事数, 先頭の最小値}
    for (int t=maxt; t>=0; t--) {
        dp[t] = dp[t+1];
        for (auto &s:sche[t]) {
            if (dp[s.se].fi + 1 > dp[t].fi || (dp[s.se].fi + 1 == dp[t].fi && s.fi < dp[t].se))
                dp[t] = {dp[s.se].fi + 1, s.fi};
        }
    }
    cout << dp[0].fi << '\n';
    for (int t=0; dp[t].fi>0; t = jobs[dp[t].se].se) {
        cout << dp[t].se + 1 << (dp[t].fi > 1 ? ' ' : '\n');
    }
    return 0;
}