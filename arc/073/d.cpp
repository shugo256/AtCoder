#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long wt;
    cin >> n >> wt;
    long w0, w[n], v[n];
    cin >> w0 >> v[0]; w[0] = 0;
    for (int i=1; i<n; i++) {
        cin >> w[i] >> v[i];
        w[i] -= w0;
    }
    long dp[101][301] = {{0}};
    for (int i=0; i<n; i++)
        for (int j=i+1; j>=1; j--)
            for (int k=300; k>=0; k--)
                if (k - w[i] >= 0) 
                    dp[j][k] = max(dp[j-1][k-w[i]] + v[i], dp[j][k]);
    long best = 0;
    for (int i=wt/w0; i>=0; i--) {
        if (i > n) continue;
        int j = min(wt - i * w0, 300l);
        best = max(best, dp[i][j]);
        // cerr << i << ' ' << j << '\n';
    }
    cout << best << '\n';
    return 0;
}