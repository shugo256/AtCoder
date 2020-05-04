#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

ll pow5(ll x) {
    ll xx = x * x;
    return xx * xx * x;
}

int main() {
    ll x;
    cin >> x;
    vector<ll> facts;
    for (ll i=1; i*i <= x; i++) {
        if (x % i) continue;
        facts.push_back(i);
        if (i * i != x) facts.push_back(x / i);
    }
    for (auto &fi:facts) {
        if (fi > 1000) continue;
        for (ll a = 0; true; a++) {
            ll b = a - fi;
            ll d = pow5(a) - pow5(b);
            if (d == x) {
                cout << a << ' ' << b << '\n';
                return 0;
            } else if (b > 0 && d > x) {
                break;
            }
        }
    }
    return 0;
}