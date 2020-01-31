#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

typedef pair<long, long> P;

int main() {
    long n;
    cin >> n;
    vector<P> ab;
    long a[3], b[3];
    for (auto &ai:a) cin >> ai;
    for (auto &bi:b) cin >> bi;
    for (long i=0; i<3; i++) {
        ab.push_back({a[i], b[i]});
    }
    long dp[5010] = {0}, best=0;
    for (long i=0; i<=n; i++) {
        dp[i+1] = max(dp[i], dp[i+1]);
        for (auto abi:ab) {
            if (i + abi.first <= n)
                dp[i + abi.first] = max(dp[i + abi.first], dp[i] + abi.second);
        }
        best = max(best, dp[i] + n - i);
    }
    n = best;
    best=0;
    vector<long> dp2(n+1, 0);
    for (long i=0; i<=n; i++) {
        for (auto abi:ab) {
            if (i + abi.second <= n)
                dp2[i + abi.second] = max(dp2[i + abi.second], dp2[i] + abi.first);
        }
        best = max(best, dp2[i] + n - i);
    }
    cout << best << '\n';
    return 0;
}
