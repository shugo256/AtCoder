#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    cout << max(a - k, 0ll) << ' ' << min(b, max(a + b - k, 0ll)) << '\n';
    return 0;
}