#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    if (k < a) cout << k << '\n';
    else if (k < a + b) cout << a << '\n';
    else cout << a - (k - a - b) << '\n';
    return 0;
}