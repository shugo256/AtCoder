#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>

using ll = long long;

using namespace std;

#define MAX_D 50
using bs = bitset<51>;

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (auto &ai:a) cin >> ai;
    for (auto &bi:b) cin >> bi;
    bs check(string(50, '1') + '0');
    bool all_fail = true;
    for (int i=MAX_D; i>=1; i--) {
        bool needed = false;
        check.reset(i);
        for (int j=0; j<n; j++) {
            bs dp;
            dp.set(a[j]);
            for (int k=MAX_D; k>=1; k--) {
                if (!check[k]) continue;
                bs filter((1ll << k) - 1),
                   buf = dp;
                for (int l=0; l<(51 + k - 1) / k; l++) {
                    buf >>= k;
                    dp |= (buf & filter);
                }
            }
            if (!dp[b[j]]) {
                needed = true;
                break;
            }
        }
        if (needed) check.set(i);
        else all_fail = false;
    }
    cout << (all_fail ? -1ll : (ll)check.to_ullong()) << '\n';
    return 0;
}