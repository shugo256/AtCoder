#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    ll best = 0, a[n];
    for (auto &ai:a) {
        cin >> ai;
        best = max(best, ai);
    }
    ll l = 0, r = best;
    while (r - l > 1) {
        ll m = (l + r + 1) / 2;
        ll sum = 0;
        for (auto &ai:a) {
            sum += (ai - 1) / m;
        }
        if (sum <= k) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
    return 0;
}