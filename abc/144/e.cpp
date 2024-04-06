#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    long k;
    cin >> n >> k;
    long sum=0, a[n], f[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (auto &fi:f) cin >> fi;
    sort(a, a+n);
    sort(f, f+n, greater<long>());
    long l=-1, r=10000000000000;
    while (r - l > 1) {
        long m = (l + r + 1) / 2, train=0;
        for (int i=0; i<n; i++) {
            train += min(a[i], m / f[i]);
        }
        if (train + k < sum) l = m;
        else r = m;
    }
    cout << r << '\n';
    return 0;
}