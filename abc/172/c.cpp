#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, m; ll k;
    cin >> n >> m >> k;
    ll a[n+1], b[m+1];
    a[0] = b[0] = 0;
    for (int i=0, ai; i<n; i++) {
        cin >> ai;
        a[i+1] = a[i] + ai;
    }
    for (int i=0, bi; i<m; i++) {
        cin >> bi;
        b[i+1] = b[i] + bi;
    }
    int ans = 0;
    for (int i=0; i<=n; i++) {
        ll left = k - a[i];
        if (left < 0) break;
        int j = partition_point(b, b+m+1, [&](ll x) {
            return x <= left;
        }) - b - 1;
        ans = max(ans, i + j);
    }
    cout << ans << '\n';
    return 0;
}