#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;

using namespace std;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << (4*a*b < (c - a - b) * (c - a - b) && c - a - b >= 0 ? "Yes" : "No") << '\n';
    return 0;
}