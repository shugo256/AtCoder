#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
T gcd(T a, T b) {
    if (a > b) {
        T buf = a;
        a = b;
        b = buf;
    }
    return a == 0 ? b : gcd(a, b%a);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        long a, b, c, d;
        cin >> a >> b >> c >> d;
        long ra = a % b;
        if (ra == a || ra > c) {
            cout << "No" << '\n';
            continue;
        }
        else if (b < c && b <= d) {
            cout << "Yes" << '\n';
            continue;
        }
        long g   = gcd(b, d),
             q1  = (c - ra) / g + 1,
             rra = ra % g;
        cout << (ra + g*q1 < b || rra + d < c ? "No" : "Yes") << '\n';
    }
    return 0;
}