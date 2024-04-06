#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

using P = pair<long, long>;
#define fi first
#define se second

#define INF 1000000000000

int main() {
    int n;
    cin >> n;
    P probs[n];
    long ans = 0;
    for (auto &p:probs) {
        cin >> p.fi >> p.se;
        ans = max(ans, p.se - p.fi + 1);
    }
    sort(probs, probs+n);
    long rmin = INF;
    P from_back[n+1];
    fill(from_back, from_back+n+1, P{0, INF});
    for (int i=n-1; i>=0; i--) {
        from_back[i].fi = max(from_back[i+1].fi, probs[i].fi);
        from_back[i].se = min(from_back[i+1].se, probs[i].se);
    }
    for (int i=0; i<n-1; i++) {
        P p = probs[i], fb = from_back[i+1];
        if (i > 0) {
            long maxl = fb.fi,
                 minr = min(rmin, fb.se);
            ans = max(ans, p.se - p.fi + 1 + max(0l, minr - maxl + 1));
        }
        rmin = min(rmin, p.se);
        ans = max(ans, max(0l, rmin - p.fi + 1) + max(0l, fb.se - fb.fi + 1));
    }
    cout << ans << '\n';
    return 0;
}