#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    ll a1, a2, target = 0; 
    cin >> n >> a1 >> a2;
    for (int i=2; i<n; i++) {
        ll ai; cin >> ai;
        target ^= ai;
    }
    ll sum = a1 + a2, new1 = 0;
    ll next = 0;
    vector<ll> addable;
    for (ll i=40; i>=0; i--) {
        ll x = (target >> i) & 1;
        ll s = (sum >> i) & 1;
        if (x == 0) {
            new1 += next * (1ll << i);
            next = s;
        } else {
            if (s == next) {
                cout << -1 << '\n';
                return 0;
            } else {
                addable.push_back(1ll << i);
            }
        }
    }
    for (auto &adi:addable) if (new1 + adi <= a1) new1 += adi;
    cout << (new1 <= a1 && new1 > 0 && next == 0 ? a1 - new1 : -1) << '\n';
    return 0;
}