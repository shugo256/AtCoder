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

int main() {
    int n;
    ll d, a;
    cin >> n >> d >> a;
    P mons[n];
    for (auto &mi:mons) cin >> mi.fi >> mi.se;
    sort(mons, mons+n);
    queue<P> boms;
    ll bomsum = 0, ans = 0;
    for (int i=0; i<n; i++) {
        ll xi = mons[i].fi, hi = mons[i].se;
        while (!boms.empty() && boms.front().fi < xi) {
            bomsum -= boms.front().se;
            boms.pop();
        }
        hi -= bomsum;
        if (hi <= 0) continue;
        ll cnt = (hi + a - 1) / a;
        ans += cnt;
        bomsum += cnt * a;
        boms.push({xi + 2*d, cnt*a});
    }
    cout << ans << '\n';
    return 0;
}