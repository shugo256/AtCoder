#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

int main() {
    int n;
    cin >> n;
    int b = (1 << n);
    vector<P> test[n];
    for (int i=0, ai; i<n; i++) {
        cin >> ai;
        for (int j=0, x, y; j<ai; j++) {
            cin >> x >> y;
            x--;
            test[i].push_back({x, y});
        }
    }
    int ans = 0, cnt;
    for (int i=0; i<b; i++) {
        cnt = 0;
        bool yes = true;
        for (int j=0; j<n; j++) {
            if (i & (1 << j)) {
                cnt++;
                for (auto &ti:test[j]) {
                    if (ti.se != ((i >> ti.fi) & 1)) yes = false;
                }
            }
        }
        if (yes) {
            ans = max(ans, cnt);
        }
    }
    cout << ans << '\n';
    return 0;
}