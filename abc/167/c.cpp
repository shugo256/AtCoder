#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define INF 10000000

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    int c[n], a[n][m];
    for (int i=0; i<n; i++) {
        cin >> c[i];
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = INF;
    for (int i=0; i<(1 << n); i++) {
        int rikai[m], cost = 0;
        fill(rikai, rikai+m, 0);
        for (int d=0; d<n; d++) {
            if (i & (1 << d)) {
                cost += c[d];
                for (int j=0; j<m; j++) {
                    rikai[j] += a[d][j];
                }
            }
        }
        bool success = true;
        for (auto &ri:rikai) if (ri < x) success = false;
        if (success) ans = min(ans, cost);
    }
    cout << (ans < INF ? ans : -1) << '\n';
    return 0;
}