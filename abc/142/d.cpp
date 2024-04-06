#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;

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
    long a, b;
    cin >> a >> b;
    long g = gcd(a, b), r = (long)sqrt(g);
    int cnt = 1;
    for (int i=2; i<=r; i++) {
        if (g % i == 0) {
            while (g % i == 0) g /= i;
            cnt++;
        }
    }
    if (g != 1) cnt++;
    cout << cnt << '\n';
    return 0;
}