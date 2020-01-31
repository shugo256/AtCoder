#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>
#include <complex>

using ll = long long;

using namespace std;

#define EPS (1e-9)

using P = pair<int, int>;
#define fi first
#define se second

int main() {
    int n;
    cin >> n;
    P ps[n];
    for (auto &pi:ps) cin >> pi.fi >> pi.se;
    sort(ps, ps+n);
    double l = 0, r = 1000;
        cerr << ps[0].fi << endl;
    while (r - l > EPS) {
        double m = (l + r) / 2;
        P p1 = ps[0];
        bool yes = true, allin = true;
        double low = -M_PI, up = M_PI;
        for (int i=1; i<n; i++) {
            P vi = {ps[i].fi - p1.fi, ps[i].se - p1.se};
            double d = hypot(vi.fi, vi.se) / 2;
            if (2*d > m) allin = false;
            if (d > m) {
                yes = false;
                break;
            }
            double delta = acos(d / m);
            double midle = arg(complex<double>(vi.fi, vi.se));
            double l1 = midle - delta, u1 = midle + delta;
            if (u1 < low || l1 > up) {
                yes = false;
                break;
            }
            low = max(low, l1);
            up = min(up, u1);
        }
        if (yes || allin) {
            r = m;
        } else {
            P p1 = ps[n-1];
            bool yes = true, allin = true;
            double low = -M_PI, up = M_PI;
            for (int i=0; i<n-1; i++) {
                P vi = {ps[i].fi - p1.fi, ps[i].se - p1.se};
                double d = hypot(vi.fi, vi.se) / 2;
                if (2*d > m) allin = false;
                if (d > m) {
                    yes = false;
                    break;
                }
                double delta = acos(d / m);
                double midle = arg(complex<double>(-vi.fi, -vi.se));
                double l1 = midle - delta, u1 = midle + delta;
                if (u1 < low || l1 > up) {
                    yes = false;
                    break;
                }
                low = max(low, l1);
                up = min(up, u1);
            }
            if (yes || allin) r = m;
            else l = m;
        }
    }
    cout << setprecision(15) << fixed << l << '\n';
    return 0;
}