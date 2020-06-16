#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;

using namespace std;

int main() {
    ll a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;
    ll dif = abs(a - b);
    cout << (w * t + dif <= v * t ? "YES" : "NO") << '\n';
    return 0;
}