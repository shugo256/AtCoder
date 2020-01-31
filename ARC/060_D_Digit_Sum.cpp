#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long n, s;
    cin >> n >> s;
    if (s >= n) {
        cout << (s==n ? n + 1 : -1) << '\n';
        return 0;
    }
    long r = sqrt(n);
    for (long b=2; b<=r; b++) {
        long f = 0;
        for (long _n=n; _n>0; _n/=b) f += _n % b;
        if (f == s) {
            cout << b << '\n';
            return 0;
        }
    }
    long d1 = min(n/(r+1), s);
    for ( ; d1>0; d1--) {
        long d0 = s - d1;
        if ((n - d0) % d1 == 0 && (n - d0) / d1 > d1 && (n - d0) / d1 > d0) {
            cout << (n - d0) / d1 << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}