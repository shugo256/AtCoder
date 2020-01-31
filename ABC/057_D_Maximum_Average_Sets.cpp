#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

long comb(long n, long k) {
    if (n < k || k < 0) return 0;
    if (n == k || k == 0) return 1;
    return comb(n-1, k-1) * n / k;
}

int main() {
    long n, a, b;
    cin >> n >> a >> b;
    map<long, long, greater<long>> m;
    for (long i=0; i<n; i++) {
        long v;
        cin >> v;
        m[v]++;
    }
    bool first = true;
    long sum=0, orga = a;
    for (auto p:m) {
        if (a <= p.second) {
            if (first) {
                long lim = min(b, p.second),
                     ans = 0;
                for (long i=a; i<=lim; i++) ans += comb(p.second, i);
                cout << p.first << '\n' << ans << '\n';
            } else {
                sum += p.first * a;
                cout << setprecision(10) 
                     << (double)sum / orga << '\n'
                     << comb(p.second, a) << '\n';
            }
            return 0;
        }
        if (first) first = false;
        a -= p.second;
        b -= p.second;
        sum += p.first * p.second;
    }
    return 0;
}