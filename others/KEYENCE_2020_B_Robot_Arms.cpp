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
    cin >> n;
    P xl[n];
    for (auto &xli: xl) cin >> xli.fi >> xli.se;
    sort(xl, xl+n, [](P l, P r) {
        return l.fi + l.se < r.fi + r.se;
    });
    ll cur = -1e10;
    int ans = 0;
    for (auto &xli:xl) {
        if (xli.fi - xli.se < cur) continue;
        cur = xli.fi + xli.se;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}