#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    long a[n];
    for (auto &ai:a) cin >> ai;
    int i = (n+1)%2,
        j = n/2;
    long border[n], sum[n];
    sum[j] = 0;
    for (int k=j; k<n; k++) sum[j] += a[k];
    for ( ; j<n-1; j++) {
        sum[j+1] = sum[j] - a[j] + a[i];
        border[j] = (a[i] + a[j]) / 2;
        i += 2;
    }
    border[n-1] = (long)1e9 + 1;
    for (int k=0; k<q; k++) {
        long x;
        cin >> x;
        long ans = lower_bound(border+n/2, border+n, x) - border;
        cout << sum[ans] << '\n';
    }
    return 0;
}