#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> offsets(m, -1);
    vector<int> idxs(m+1), inv(m+1);
    offsets[x] = x;
    idxs[0] = x;
    inv[x] = 0;
    ll ai = x, sum = x;
    for (int i=1; i<=m; i++) {
        ai = (ai * ai) % m;
        // cerr << ai << ' '  << sum << '\n';
        sum += ai;
        if (i+1 == n) {
            cout << sum << '\n';
            break;
        }
        if (offsets[ai] >= 0) {
            ll loop_len = i - inv[ai];
            ll loop_sum = sum - offsets[ai];
            ll rest_idx = (n - inv[ai] - 1) % loop_len;
            ll rest_sum = offsets[idxs[inv[ai] + rest_idx]] - offsets[ai];
            // cerr << ai << ' ' << loop_len << ' ' << loop_sum << '\n';
            sum += ((n - inv[ai] - 1) / loop_len - 1) * loop_sum + rest_sum;
            cout << sum << '\n';
            break;
        }
        idxs[i] = ai;
        inv[ai] = i;
        offsets[ai] = sum;
    }
    return 0;
}