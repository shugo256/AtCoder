#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using ll = long long;

using namespace std;

#define INF 10000

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> G[n];
    for (int i=0, s, t; i<m; i++) {
        cin >> s >> t;
        G[s].push_back(t);
    }
    double dp[n+1];
    dp[n] = 0;
    int max_dest[n];
    for (int i=n-1; i>0; i--) {
        double maxv=0, sum = 0; 
        int maxi=-1, cnt = 0;
        for (auto g:G[i]) {
            if (dp[g] > maxv) {
                maxv = dp[g];
                maxi = g;
            }
            sum += dp[g];
            cnt++;
        }
        max_dest[i] = maxi;
        dp[i] = sum / cnt + 1;
    }
    double ans = dp[1];
    for (int j=1; j<n; j++) {
        fill(dp, dp+n, INF);
        dp[n] = 0;
        for (int i=n-1; i>0; i--) {
            double sum = 0; 
            int cnt = 0;
            for (auto g:G[i]) {
                if (i == j && g == max_dest[i]) continue;
                sum += dp[g];
                cnt++;
            }
            if (cnt == 0) continue;
            dp[i] = sum / cnt + 1;
        }
        ans = min(ans, dp[1]);
    }
    cout << setprecision(15) << ans << '\n';
    return 0;
}