#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int an, bn, m;
    cin >> an >> bn >> m;
    int a[an], b[bn], mia=1000000, mib = 1000000;
    for (auto &ai:a) {
        cin >> ai;
        mia = min(ai, mia);
    }
    for (auto &bi:b) {
        cin >> bi;
        mib = min(bi, mib);
    }
    int ans = mia + mib;
    for (int i=0, x, y, c; i<m; i++) {
        cin >> x >> y >> c;
        x--; y--;
        ans = min(ans, a[x] + b[y] - c);
    }
    cout << ans << '\n';
    return 0;
}