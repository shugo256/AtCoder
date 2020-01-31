#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define minimize(a, b) a = min(a, b)

int main() {
    int n;
    cin >> n;
    long rui[n+1];
    rui[0] = 0;
    long ans = 1000000000000000000;
    for (int i=1; i<=n; i++) {
        long ai;
        cin >> ai;
        rui[i] = ai + rui[i-1];
    }
    for (int m=0; m<=n; m++) {
        long lsum = rui[m],
             rsum = rui[n] - lsum;
        int l = upper_bound(rui,   rui+m, lsum / 2) - rui,
            r = upper_bound(rui+m, rui+n, lsum + rsum / 2) - rui;
        long P, Q, R, S;
        if (l == 0 || abs(lsum - rui[l] * 2) < abs(lsum - rui[l-1] * 2))
            P = rui[l];
        else 
            P = rui[l-1];
        Q = lsum - P;
        if (r == m || abs(rsum - (rui[r] - rui[m]) * 2) < abs(rsum - (rui[r-1] - rui[m]) * 2))
            R = rui[r] - rui[m];
        else 
            R = rui[r-1] - rui[m];
        S = rsum - R;
        minimize(ans, max({P, Q, R, S}) - min({P, Q, R, S}));
    }
    cout << ans << '\n';
    return 0;
}