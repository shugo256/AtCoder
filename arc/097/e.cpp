#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define INF 10000000

#define minimize(a, b) a = min(a, b)

int main() {
    int n;
    cin >> n;
    int white[n], black[n],
        wrui[n+1][2*n+1], brui[n+1][2*n+1];
    fill(wrui[0], wrui[n+1], 0);
    fill(brui[0], brui[n+1], 0);
    for (int i=0, a; i<2*n; i++) {
        char c;
        cin >> c >> a;
        a--;
        if (c == 'W') {
            white[a] = i;
            for (int j=a+1; j<=n; j++) wrui[j][i]++;
        }
        else {
            black[a] = i;
            for (int j=a+1; j<=n; j++) brui[j][i]++;
        }
    }
    for (int i=0; i<=n; i++) {
        for (int j=2*n; j>0; j--) {
            wrui[i][j-1] += wrui[i][j];
            brui[i][j-1] += brui[i][j];
        }
    }
    int dp[n+1][n+1];
    fill(dp[0], dp[n+1], INF);
    dp[0][0] = 0;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            if (i < n) minimize(dp[i+1][j], dp[i][j] + wrui[i][white[i]] + brui[j][white[i]]);
            if (j < n) minimize(dp[i][j+1], dp[i][j] + wrui[i][black[j]] + brui[j][black[j]]);
        }
    }
    cout << dp[n][n] << '\n';
    return 0;
}