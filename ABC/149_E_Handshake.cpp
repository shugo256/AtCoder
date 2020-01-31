#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using ll = long long;

using namespace std;

int main() {
    int n;
    ll m;
    cin >> n >> m;
    ll a[n];
    for (auto &ai:a) cin >> ai;
    sort(a, a+n, greater<ll>());
    ll l = 2 * a[n-1], r = 2 * a[0] + 1;
    int nums[n];
    while (r - l > 1) {
        ll mid = (l + r) / 2,
           sum = 0;
        for (int i=0; i<n; i++) {
            auto itr = partition_point(a, a+n, [&](ll x) {
                return x >= mid - a[i];
            });
            nums[i] = itr - a;
            sum += nums[i];
        }
        if (sum >= m) l = mid;
        else r = mid;
    }
    ll rui[n+1];
    rui[0] = 0;
    for (int i=0; i<n; i++) rui[i+1] = rui[i] + a[i];
    ll ans = 0,
       cnt = 0;
    for (int i=0; i<n; i++) {
        auto itr = partition_point(a, a+n, [&](ll x) {
            return x >= l - a[i];
        });
        ll k = itr - a;
        cnt += k;
        ans += rui[k] + a[i] * k;
    }
    cout << ans - (cnt - m) * l << '\n';
    return 0;
}