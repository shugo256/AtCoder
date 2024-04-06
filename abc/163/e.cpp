#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;

using namespace std;

using P = pair<ll, int>;
#define fi first
#define se second

#define amax(a, b) a = max(a, b)

int main() {
    int n;
    cin >> n;
    int i = 0;
    P babies[n]; 
    for (auto &bi:babies) {
        cin >> bi.fi;
        bi.se = i++;
    }
    sort(babies, babies+n, greater<P>());
    // for (auto &bi:babies) cerr << bi.fi << ' ' << bi.se << '\n';
    ll dp[n+1][n+1];
    fill(dp[0], dp[n+1], 0);
    for (int w=n; w>0; w--) {
        P baby = babies[n-w];
        // cerr << baby.fi << ' ' << baby.se << '\n';
        for (int j=0; j+w<=n; j++) {
            amax(dp[j][j+w-1], dp[j][j+w] + baby.fi * abs(j+w-1 - baby.se));
            amax(dp[j+1][j+w], dp[j][j+w] + baby.fi * abs(j - baby.se));
        }
    }
    ll ans = 0;
    for (int i=0; i<=n; i++) amax(ans, dp[i][i]);
    cout << ans << '\n';
    return 0;
}