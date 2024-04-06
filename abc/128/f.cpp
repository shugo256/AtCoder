#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    long s[n];
    for (auto &si:s) cin >> si;
    long dp, best=0;
    for (int c=1; c<n; c++) {
        dp = 0;
        for (int k=1; k<=(n-1)/c-1; k++) {
            if ((n-1) % c == 0 && n-1 <= 2*k*c) break;
            dp += s[n-k*c-1] + s[k*c];
            best = max(best, dp);
            // cerr << c << ' ' << k << ' ' << dp << '\n';
        }
    } 
    cout << best << '\n';
    return 0;
}
