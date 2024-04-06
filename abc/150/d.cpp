#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

template <typename T>
T gcd(T a, T b) {
    if (a > b) swap(a, b);
    return a == 0 ? b : gcd(b % a, a);
}

template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

int main() {
    int n;
    ll m;
    cin >> n >> m;
    ll al = 1, prev;
    for (int i=0; i<n; i++) {
        ll ai; cin >> ai;
        al = lcm(al, ai / 2);
        ll log = 0;
        while (ai % 2 == 0) { ai >>= 1; log++; }
        if (al > m || (i > 0 && log != prev)) {
            cout << 0 << '\n';
            return 0;
        }
        prev = log;
    }
    cout << (m / al) - (m / (2 * al)) << '\n';
    return 0;
}