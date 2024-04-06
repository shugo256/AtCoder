#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define long long long

using namespace std;

int main() {
    int n;
    long k;
    cin >> n >> k;
    long a[n];
    for (auto &ai:a) cin >> ai;
    sort(a, a+n);
    int l = -1, r = n;
    while (r - l > 1) {
        int m = (l + r + 1) / 2;
        bool dp[k];
        fill(dp, dp+k, 0);
        dp[0] = true;
        for (int i=0; i<n; i++) {
            if (i == m) continue;
            for (long j=k-1-a[i]; j>=0; j--)
                dp[j+a[i]] |= dp[j];
        }
        long start = max(k-a[m], 0ll);
        if (any_of(dp+start, dp+k, [](bool b) { return b; }))
            r = m;
        else
            l = m;
    }
    cout << r << '\n';
    return 0;
}