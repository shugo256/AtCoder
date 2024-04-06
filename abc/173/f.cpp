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
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        ans += (ll)i * (n - i + 1);
    }
    for (int i=0, ui, vi; i<n-1; i++) {
        cin >> ui >> vi;
        if (vi < ui) swap(ui, vi);
        ans -= (ll) (ui) * (n - vi + 1);
    }
    cout << ans << '\n';
    return 0;
}