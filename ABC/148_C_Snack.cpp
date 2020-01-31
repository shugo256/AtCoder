#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

template <typename T>
T gcd(T a, T b) {
    if (a > b) {
        T buf = a;
        a = b;
        b = buf;
    }
    return a == 0 ? b : gcd(a, b % a);
}

template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << lcm(a, b) << '\n';
    return 0;
}