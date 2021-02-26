#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

#define amin(a, b) a = min(a, b)

int main() {
    int n, q;
    cin >> n >> q;
    set<int> bot_idx, left_idx;
    bot_idx.insert(n), left_idx.insert(n);
    vector<int> bot_lim(n+1, n), left_lim(n+1, n);
    ll ans = ll(n-2) * (n-2);
    for (int i=0, t, x; i<q; i++) {
        cin >> t >> x;
        if (t == 1) {
            int a = *bot_idx.lower_bound(x);
            int cnt = bot_lim[a] - 1;
            ans -= cnt - 1;
            left_idx.insert(cnt);
            amin(left_lim[cnt], x);
            // cerr << t << ' ' << cnt << ' ' << a << '\n';
        } else {
            int a = *left_idx.lower_bound(x);
            int cnt = left_lim[a] - 1;
            ans -= cnt - 1;
            bot_idx.insert(cnt);
            amin(bot_lim[cnt], x);
            // cerr << t << ' ' << cnt << ' ' << a << '\n';
        }
    }
    cout << ans << '\n';
    return 0;
}