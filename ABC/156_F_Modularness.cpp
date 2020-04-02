#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int k, q;
    cin >> k >> q;
    ll d[k]; for (auto &di:d) cin >> di;
    ll n[q], x[q], m[q];
    for (int i=0; i<q; i++) cin >> n[i] >> x[i] >> m[i];
    ll rui[k+1];
    for (int i=0; i<q; i++) {
        rui[0] = 0;
        for (int j=0; j<k; j++) {
            rui[j+1] = rui[j] + (d[j] + m[i] - 1) % m[i] + 1;
        }
        ll last = x[i] + ((n[i]-1) / k) * rui[k] + rui[(n[i]-1) % k];
        cout << n[i] - 1 - (last / m[i] - x[i] / m[i]) << '\n';
    }
    return 0;
}