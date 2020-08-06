#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

#define INF 10000000

int main() {
    int n;
    cin >> n;
    map<P, char> dir;
    map<int, vector<int>> x, y, xPy, xSy;
    for (int i=0; i<n; i++) {
        P p;
        char u; cin >> p.fi >> p.se >> u;
        dir[p] = u;
        x[p.fi].push_back(p.se);
        y[p.se].push_back(p.fi);
        xPy[p.fi+p.se].push_back(p.fi);
        xSy[p.fi-p.se].push_back(p.fi);
    }
    int ans = INF;
    for (auto &[xi, vi]:x) {
        sort(vi.begin(), vi.end());
        int umax = -INF;
        for (auto &yi:vi) {
            if (dir[P{xi, yi}] == 'U') umax = yi;
            if (dir[P{xi, yi}] == 'D' && umax > -INF) {
                ans = min(ans, (yi - umax) * 10 / 2);
            }
        }
    }
    for (auto &[yi, vi]:y) {
        sort(vi.begin(), vi.end());
        int rmax = -INF;
        for (auto &xi:vi) {
            if (dir[P{xi, yi}] == 'R') rmax = xi;
            if (dir[P{xi, yi}] == 'L' && rmax > -INF) {
                ans = min(ans, (xi - rmax) * 10 / 2);
            }
        }
    }
    for (auto &[xpy, vi]:xPy) {
        sort(vi.begin(), vi.end());
        int dmax = -INF, rmax = -INF;
        for (auto &xi:vi) {
            int yi = xpy - xi;
            if (dir[P{xi, yi}] == 'U' && rmax > -INF) {
                ans = min(ans, (xi - rmax) * 10);
            }
            if (dir[P{xi, yi}] == 'R') rmax = xi;
            if (dir[P{xi, yi}] == 'D') dmax = xi;
            if (dir[P{xi, yi}] == 'L' && dmax > -INF) {
                ans = min(ans, (xi - dmax) * 10);
            }
        }
    }
    for (auto &[xsy, vi]:xSy) {
        sort(vi.begin(), vi.end());
        int umax = -INF, rmax = -INF;
        for (auto &xi:vi) {
            int yi = xi - xsy;
            if (dir[P{xi, yi}] == 'U') umax = xi;
            if (dir[P{xi, yi}] == 'R') rmax = xi;
            if (dir[P{xi, yi}] == 'D' && rmax > -INF) {
                ans = min(ans, (xi - rmax) * 10);
            }
            if (dir[P{xi, yi}] == 'L' && umax > -INF) {
                ans = min(ans, (xi - umax) * 10);
            }
        }
    }
    if (ans < INF) cout << ans << '\n';
    else cout << "SAFE" << '\n';
    return 0;
}