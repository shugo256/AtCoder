#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define INF (int)(1e9)
#define minimize(a, b) a = min(a, b)

int dp[10010];

int main() {
    int h, n;
    cin >> h >> n;
    int a[n], b[n];
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
    }
    fill(dp, dp+h+1, INF);
    dp[0] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<h; j++) {
            minimize(dp[min(j+a[i], h)], dp[j] + b[i]);
        }
    }
    cout << dp[h] << '\n';
    return 0;
}