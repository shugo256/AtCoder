#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    ll h[n];
    for (auto &hi:h) cin >> hi;
    sort(h, h+n, greater<ll>());
    ll ans = 0;
    for (int i=k; i<n; i++) {
        ans += h[i];
    }
    cout << ans << '\n';
    return 0;
}