#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;

using namespace std;

using P = pair<ll, ll>;
#define fi first
#define se second

int main() {
    int q;
    cin >> q;
    ll pow3_30 = 1;
    for (int i=0; i<30; i++) pow3_30 *= 3;
    while (q--) {
        P p1, p2, b1, b2, r1, r2;
        cin >> p1.fi >> p1.se >> p2.fi >> p2.se;
        p1.fi--; p1.se--; p2.fi--; p2.se--;
        ll pow = pow3_30;
        ll dist = abs(p1.fi - p2.fi) + abs(p1.se - p2.se);
        while (pow /= 3) {
            b1 = {p1.fi / pow, p1.se / pow};
            b2 = {p2.fi / pow, p2.se / pow};
            r1 = {p1.fi % pow, p1.se % pow};
            r2 = {p2.fi % pow, p2.se % pow};
            if (b1.fi != b2.fi && b1.se != b2.se) {
                break;
            } else if (b1.fi == b2.fi && b1.se != b2.se && b1.fi % 3 == 1 && (b1.se+1) / 3 != (b2.se+1) / 3) {
                dist = abs(p1.se - p2.se) + min(r1.fi + r2.fi + 2, (pow-r1.fi) + (pow-r2.fi));
                break;
            } else if (b1.fi != b2.fi && b1.se == b2.se && b1.se % 3 == 1 && (b1.fi+1) / 3 != (b2.fi+1) / 3) {
                dist = abs(p1.fi - p2.fi) + min(r1.se + r2.se + 2, (pow-r1.se) + (pow-r2.se));
                break;
            }
        }
        cout << dist << '\n';
    }
    return 0;
}