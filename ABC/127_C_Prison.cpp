#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int lmax=0, rmin=n;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        lmax = max(lmax, l);
        rmin = min(rmin, r);
    }
    cout << max(rmin - lmax + 1, 0) << '\n';
    return 0;
}
