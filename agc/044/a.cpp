#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

#define LIM ((ll)1e18)

using P = pair<ll, ll>;
#define fi first
#define se second

int main() {
    int T; cin >> T;
    while (T--) {
        ll n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        map<ll, ll> mp;
        for (ll i=max(n-4, 1ll); i<=n+4; i++)
            mp[i] = d * abs(n - i);
        ll ans = (n > 5 ? 1e18 : d * n);
        while (!mp.empty()) {
            P f = *mp.rbegin(); mp.erase(f.fi);
            vector<P> cands;
            for (int i=-4; i<=4; i++) {
                if (f.fi % 2 == 0) 
                    cands.push_back({f.fi / 2 + i, f.se + d * abs(i) + a});
                if (f.fi % 3 == 0) 
                    cands.push_back({f.fi / 3 + i, f.se + d * abs(i) + b});
                if (f.fi % 5 == 0) 
                    cands.push_back({f.fi / 5 + i, f.se + d * abs(i) + c});
            }
            for (auto &ci:cands) {
                if (ci.fi <= 0 || ci.fi >= f.fi || ci.se > ans) continue;
                if (ci.fi <= (ans - ci.se) / d) {
                    ans = min(ans, ci.fi * d + ci.se);
                }
                if (!mp.count(ci.fi) || ci.se < mp[ci.fi]) {
                    mp[ci.fi] = ci.se;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}