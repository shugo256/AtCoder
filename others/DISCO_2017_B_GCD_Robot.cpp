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

// 最小公倍数
template <typename T>
T lcm(T a, T b) {
    return a  / gcd(a, b) * b;
}

int main() {
    int n;
    long z;
    cin >> n >> z;
    long ans = 1;
    for (int i=0; i<n; i++) {
        long a;
        cin >> a;
        ans = lcm(ans, gcd(a, z));
    }
    cout << ans << '\n';
    return 0;
}