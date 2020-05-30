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
    ll a[n+1];
    for (auto &ai:a) cin >> ai;
    if (a[n] == 0) {
        cout << -1 << '\n';
        return 0;
    }
    ll rui[n+2];
    rui[n+1] = 0;
    for (int i=n; i>=0; i--) {
        rui[i] = rui[i+1] + a[i];
    }
    ll ans = 0, now = 1;
    for (int i=0; i<=n; i++) {
        ans += now;
        if (now < a[i]) {
            cout << -1 << '\n';
            return 0;
        }
        now -= a[i];
        now = min(now * 2, rui[i+1]);
    }
    cout << ans << '\n';
    return 0;
}