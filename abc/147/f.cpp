#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

#define fi first
#define se second

int main() {
    long n, x, d;
    cin >> n >> x >> d;
    if (d < 0) {
        x += (n-1) * d;
        d = -d;
    }
    if (d == 0) {
        cout << (x == 0 ? 1 : n+1) << '\n';
        return 0;
    }
    long ma[n+1], mi[n+1];
    for (long i=0; i<=n; i++) {
        ma[i] = (n - i + n - 1) * i / 2 + 1;
        mi[i] = (0 + i - 1) * i / 2;
        // cerr << i << ' ' << mi[i] << ' ' << ma[i] << '\n';
    }
    map<long, map<long, int>> segs;
    for (int k=0; k<=n; k++) {
        long mul = x * k, r = (mul % d + d) % d;
        segs[r][mi[k] + (mul - r) / d] += 1;
        segs[r][ma[k] + (mul - r) / d] -= 1;
        // cerr << k << ' ' << mi[k] + (mul - r) / d << ' ' << ma[k] + (mul - r) / d << '\n';
    }
    long ans = 0;
    for (auto &sp:segs) {
        auto seg = sp.se;
        // cerr << sp.fi << '\n';
        long flag = 0, start;
        for (auto &s:seg) {
            // cerr << flag << ' ' << s.fi << '\n';
            if (flag == 0 && s.se > 0)
                start = s.fi;
            if (flag > 0 && s.se == -flag)
                ans += s.fi - start;
            flag += s.se;
        }
    }
    cout << ans << '\n';
    return 0;
}