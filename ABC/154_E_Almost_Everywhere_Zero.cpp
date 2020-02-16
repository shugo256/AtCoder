#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    string n;
    int k;
    cin >> n >> k;
    int len = n.size();
    ll dp[len+1][k+1][2];
    fill(dp[0][0], dp[len+1][0], 0);
    dp[0][0][0] = 1;
    for (int i=0; i<len; i++) {
        for (int j=0; j<=k; j++) {
            dp[i+1][j][n[i] != '0'] += dp[i][j][0];
            dp[i+1][j][1] += dp[i][j][1];
            if (j < k) {
                dp[i+1][j+1][1] += dp[i][j][0] * max(n[i] - '1', 0);
                if (n[i] != '0') dp[i+1][j+1][0] += dp[i][j][0];
                dp[i+1][j+1][1] += dp[i][j][1] * 9;
            }
        }
    }
    cout << dp[len][k][0] + dp[len][k][1] << '\n';
    return 0;
}