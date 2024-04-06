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

#define INF ((ll)3e9)

bool in_range(ll val, P range) {
    return range.fi <= val && val <= range.se;
}

#define amin(a, b) a = min(a, b)
#define amax(a, b) a = max(a, b)

int main() {
    int n;
    cin >> n;
    vector<P> points(n);
    for (auto &pi:points) {
        cin >> pi.fi >> pi.se;
    }
    ll l = -1, r = INF;
    while (r - l > 1) {
        ll m = (l + r + 1) / 2;
        P plus = {-INF, +INF}, minus = plus;
        bool yes = true;
        for (auto &pi:points) {
            int pl = pi.fi + pi.se,
                mi = pi.fi - pi.se;
            if (!in_range(pl, plus) || !in_range(mi, minus)) {
                yes = false;
                break;
            }
            amax(plus.fi,  pl - m);
            amin(plus.se,  pl + m);
            amax(minus.fi, mi - m);
            amin(minus.se, mi + m);
        }
        if (yes) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
    return 0;
}