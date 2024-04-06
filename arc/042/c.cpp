#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define maxi(a, b) a = max(a, b)

using P = pair<int, int>;
#define fi first
#define se second

int main() {
    int n, p;
    cin >> n >> p;
    int dp[n+1][p+1][2];
    fill(dp[0][0], dp[n+1][0], 0);

    P oyatsu[n];
    for (auto &oi:oyatsu) cin >> oi.fi >> oi.se;
    sort(oyatsu, oyatsu+n, greater<P>());

    for (int i=0; i<n; i++) {
        int a = oyatsu[i].fi, b = oyatsu[i].se;
        for (int j=0; j<=p; j++) {
            if (j + a <= p) {
                maxi(dp[i+1][j+a][0], dp[i][j][0] + b);
            }
            if (j + 1 <= p) {
                maxi(dp[i][j+1][0], dp[i][j][0]);
                maxi(dp[i][j+1][1], dp[i][j][1]);
            }
            maxi(dp[i+1][j][1], dp[i][j][0] + b);
            maxi(dp[i+1][j][0], dp[i][j][0]);
            maxi(dp[i+1][j][1], dp[i][j][1]);
        }
    }
    cout << max(dp[n][p][0], dp[n][p][1]) << '\n';
    return 0;
}