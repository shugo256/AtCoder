#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define minimize(a, b) a = min({a, b})

int main() {
    int n, m;
    cin >> n >> m;
    int a[m], c[m];
    for (int i=0, b; i<m; i++) {
        cin >> a[i] >> b;
        c[i] = 0;
        for (int j=0, _c; j<b; j++) {
            cin >> _c;
            c[i] += (1 << (_c - 1));
        }
    }
    int dp[m+1][1 << n];
    fill(dp[0], dp[m+1], 1000000000);
    dp[0][0] = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<(1<<n); j++) {
            minimize(dp[i+1][j | c[i]], dp[i][j] + a[i]);
            minimize(dp[i+1][j], dp[i][j]);
        }
    }
    cout << (dp[m][(1<<n) - 1] < 1000000000 ? dp[m][(1<<n) - 1] : -1) << '\n';
    return 0;
}
