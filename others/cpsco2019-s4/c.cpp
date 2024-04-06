#include <iostream>
#include <algorithm>

using namespace std;

long c2(long n) {
    if (n < 2) return 0;
    else return n*(n-1) / 2;
}

int main() {
    long n;
    long d;
    cin >> n >> d;
    long r[n];
    for (auto i=0; i<n; i++) cin >> r[i];
    sort(r, r+n);
    long j=0, sum=0;
    for (auto i=0; i<n; i++) {
        while (j < n && r[i] + d >= r[j]) j++;
        sum += c2(j - i - 1);
        // cerr << i << ' ' << j << ' ' << r[i] << ' ' << c2(j-i-1) << '\n';
    }
    cout << sum << '\n';
    return 0;
}