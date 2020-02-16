#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;
#define MAX (ll)(1e18)

int main() {
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (auto &ai:a)
        cin >> ai;
    sort(a, a+n);
    ll l = -MAX, r = MAX;
    while (r - l > 1) {
        ll m = (l + r) / 2,
           sum = 0;
        for (int i=0; i<n; i++) {
            if (a[i] >= 0) {
                auto pp = partition_point(a+i+1, a+n, [&](ll x) { return x * a[i] <= m; });
                sum += pp - (a+i+1);
            }
            else {
                auto pp = partition_point(a+i+1, a+n, [&](ll x) { return x * a[i] > m; });
                sum += (a+n) - pp;
            }
        }
        if (sum < k) l = m;
        else r = m;
    }
    cout << r << '\n';
    return 0;
}