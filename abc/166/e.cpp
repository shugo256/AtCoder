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
    int a[n];
    ll cnt[n];
    fill(cnt, cnt+n, 0);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (i - a[i] >= 0) cnt[i - a[i]]++;
    }
    ll ans = 0;
    for (int i=0; i<n; i++) {
        if (i + a[i] < n) ans += cnt[i + a[i]];
    }
    cout << ans << '\n';
    return 0;
}