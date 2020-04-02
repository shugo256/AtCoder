#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, p;
    string s;
    cin >> n >> p >> s;
    ll ans = 0;
    if (p == 2 || p == 5) {
        for (int i=0; i<n; i++) {
            if ((s[i] - '0') % p == 0) ans += (ll)i + 1;
        }
    } else {
        reverse(s.begin(), s.end());
        ll cnt[p];
        fill(cnt, cnt+p, 0);
        cnt[0]++;
        int r = 0, d = 1;
        for (auto &c:s) {
            int ci = c - '0';
            r = (r + ci * d) % p;
            d = (d * 10) % p;
            ans += cnt[r];
            cnt[r]++;
        }
    }
    cout << ans << '\n';
    return 0;
}