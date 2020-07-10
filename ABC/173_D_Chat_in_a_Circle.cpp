#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    ll a[n]; for (auto &ai:a) cin >> ai;
    sort(a, a+n, greater<ll>());
    ll ans = -a[0];
    for (int i=0; i<n; i++) {
        ans += a[i / 2];
    }
    cout << ans << '\n';
    return 0;
}