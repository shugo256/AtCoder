#include <iostream>
#include <algorithm>

#define INF 1000000

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int dp[n][n];
    bool edge[n][n];
    fill(dp[0], dp[n], INF);
    fill(edge[0], edge[n], 0);
    for (int i=0; i<n; i++) dp[i][i] = 0;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dp[a][b] = c;
        dp[b][a] = c;
        edge[a][b] = true;
        edge[b][a] = true;
    }
    int cnt = 0;
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (dp[i][j] > dp[i][k] + dp[k][j] && edge[i][j]) {
                    edge[i][j] = false;
                    edge[j][i] = false;
                    cnt++;
                }
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}