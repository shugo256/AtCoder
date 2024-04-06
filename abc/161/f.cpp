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
    if (n == 2) {
        cout << 1 << '\n';
        return 0;
    }
    int cnt = 2;
    for (ll i=2; i*i<=n; i++) {
        if (i*i <= n-1 && (n-1) % i == 0) {
            cnt++;
            if (i != (n-1) / i) cnt++;
        } else if (n % i == 0) {
            ll temp = n;
            while (temp % i == 0) temp /= i;
            if (temp % i == 1) cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}