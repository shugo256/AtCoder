#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    long x[n], rui[n+1];
    rui[0] = 0;
    for (int i=0; i<n; i++) {
        cin >> x[i];
        rui[i+1] = x[i] + rui[i];
    }
    for (int i=0; i<q; i++) {
        int c, d;
        cin >> c >> d;
        long j = lower_bound(x, x+n, c-d) - x,
             k = lower_bound(x, x+n, c)   - x,
             l = lower_bound(x, x+n, c+d) - x,
             ds = (j + n - l) * d,
             lsum = c * (k - j) - (rui[k] - rui[j]),
             rsum = (rui[l] - rui[k]) - c * (l - k);
        //cerr << j << ' ' << k  << ' ' << l << '\n';
        cout << ds + lsum + rsum << '\n';
    }
    return 0;
}