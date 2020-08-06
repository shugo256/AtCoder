#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define amax(a, b) a = max(a, b)

int main() {
    int n;
    cin >> n;
    int a[n]; for (auto &ai:a) cin >> ai;
    ll dp[n+1];
    fill(dp, dp + n+1, 0ll);
    dp[0] = 1000;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            amax(dp[j+1], dp[i] / a[i] * a[j] + dp[i] % a[i]);
        }
        amax(dp[i+1], dp[i]);
    }
    cout << dp[n] << '\n';
    return 0;
}