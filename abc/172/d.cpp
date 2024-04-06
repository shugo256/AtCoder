#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll q = n / i;
        ans += q * (q + 1) / 2 * i;
    }
    cout << ans << '\n';
    return 0;
}