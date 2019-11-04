#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define INF 1000000000

int main() {
    int n;
    cin >> n;
    int row[n], col[n];
    fill(row, row+n, 0);
    fill(col, col+n, 0);
    char a;
    bool black[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a;
            black[i][j] = (a == '#');
            row[i] += black[i][j];
            col[j] += black[i][j];
        }
    }
    if (all_of(row, row+n, [](int r) { return r == 0; })) {
        cout << -1 << '\n';
        return 0;
    }
    int ans = INF;
    for (int i=0; i<n; i++) {
        int cnt = 0;
        for (int j=0; j<n; j++) {
            if (black[i][j]) {
                if (col[j] < n) cnt++;
            }
            else {
                if (i >= j && col[i] == 0) {
                    cnt++;
                    col[i] = 1;
                }
                cnt += 2;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}