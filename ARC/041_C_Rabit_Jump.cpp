#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    ll ans = 0, rmax = 1, rnum = 0, rcnt = 0, lcnt = 0;
    bool right = true;
    for (int i=0, x; i<n; i++) {
        char d;
        cin >> x >> d;
        if (d == 'R') {
            if (!right) {
                right = true;
                ans += max(rcnt, lcnt);
                rnum = 0;
                rcnt = lcnt = 0;
            }
            else {
                rcnt += rnum * (x - rmax);
                rcnt -= rnum;
            }
            rmax = x;
            rnum++;
        }
        else {
            if (right) {
                right = false;
                rcnt += rnum * (x - rmax);
            }
            lcnt += x - rmax - 1;
            rmax++;
        }
        // cerr << rcnt << ' ' << lcnt << '\n';
    }
    ans += max(rcnt + l - rmax, lcnt);
    cout << ans << '\n';
    return 0;
}