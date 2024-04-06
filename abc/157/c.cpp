#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int d[3];
    d[0] = d[1] = d[2] = -1;
    for (int i=0, s, c; i<m; i++) {
        cin >> s >> c;
        if (d[--s] >= 0 && d[s] != c) {
            cout << -1 << '\n';
            return 0;
        }
        d[s] = c;
    }
    if (n > 1 && d[0] == 0) {
        cout << -1 << '\n';
        return 0;
    }
    if (n > 1 && d[0] == -1) d[0] = 1;
    int ans = 0;
    for (int i=0; i<n; i++) {
        ans += max(d[i], 0);
        if (i < n-1) ans *= 10;
    }
    cout << ans << '\n';
    return 0;
}