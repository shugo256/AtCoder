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
    return a == 0 ? b : gcd(a, b%a);
}

int main() {
    int n, k;
    cin >> n >> k;
    bool bigger = false;
    int g = 0;
    for (int i=0, ai; i<n; i++) {
        cin >> ai;
        if (ai >= k) bigger = true;
        g = gcd(g, ai);
    }
    cout << (bigger && (k % g == 0) ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
    return 0;
}