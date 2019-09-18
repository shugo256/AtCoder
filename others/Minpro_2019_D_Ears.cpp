#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int l;
    cin >> l;
    long dp[l+1][5];
    fill(dp[0], dp[l+1], 0);
    for (int i=0; i<l; i++) {
        long a; cin >> a;
        long best = 1e18;
        for (int j=0; j<5; j++) {
            dp[i+1][j] = best = min(best, dp[i][j]);
            if (j == 0 || j == 4) dp[i+1][j] += a;
            else if (j == 2) dp[i+1][j] += (a+1) % 2;
            else dp[i+1][j] += a % 2 + (a == 0 ? 2 : 0);
        }
    }
    cout << min({dp[l][0], dp[l][1], dp[l][2], dp[l][3], dp[l][4]}) << '\n';
    return 0;
}