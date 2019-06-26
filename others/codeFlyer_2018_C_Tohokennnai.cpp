#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long n, d;
    cin >> n >> d;
    long x[n];
    for (auto &xi:x) cin >> xi;
    long border[n];
    for (long i=0; i<n; i++)
        border[i] = upper_bound(x, x+n, x[i] + d) - x;
    long cnt = 0;
    for (long i=0; i<n; i++) {
        long b = border[i];
        if (b == n) break;
        for (long j=i+1; j<b; j++)
            cnt += border[j] - b;
    }
    cout << cnt << '\n';
    return 0;
}