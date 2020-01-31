#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

int main() {
    int n;
    cin >> n;
    ll a[n];
    for (auto &ai:a) cin >> ai;
    ll osum=0, esum=0;
    int maxi=0;
    bool no_plus = true;
    for (int i=0; i<n; i++) {
        if (a[i] > 0) no_plus = false;
        if (a[i] > a[maxi]) maxi = i;
        if (i % 2) osum += max(a[i], 0ll);
        else esum += max(a[i], 0ll);
    }
    if (no_plus) {
        cout << a[maxi] << '\n'
             << n - 1   << '\n';
        for (int i=n; i>maxi+1; i--) cout << i << '\n';
        for (int i=0; i<maxi; i++) cout << 1 << '\n';
        return 0;
    }
    int s = (osum > esum ? 1 : 0), c = 0, e = n-1;
    vector<int> ans;
    for ( ; (e - s) % 2 || a[e] <= 0; e--) ans.push_back(e+1);
    for ( ; (c - s) % 2 || a[c] <= 0; c++) ans.push_back(1);
    for ( ; c<e; c+=2) ans.push_back(a[c+2] > 0 ? 2 : 3);

    cout << max(osum, esum) << '\n'
         << ans.size()      << '\n';

    for (auto &ai:ans) cout << ai << '\n';

    return 0;
}