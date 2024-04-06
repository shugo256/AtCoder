#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

ll count5(ll x) {
    ll ans = 0, d = 5;
    while (d <= x) {
        ans += x / d;
        d *= 5;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    ll k = 0;;
    if (n % 2) {
        cout << 0 << '\n';
        return 0;
    }
    else n /= 2;
    cout << count5(n) - count5(k) << '\n';
    return 0;
}