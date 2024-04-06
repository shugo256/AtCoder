#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

#define MAX 100010

vector<P> G[MAX];
bitset<MAX> flip;
bool visited[MAX] = {0};
bitset<2*MAX> ans;

int dfs(int i) {
    visited[i] = true;
    int sum = flip[i];
    for (auto &g:G[i]) {
        if (visited[g.fi]) continue;
        int res = dfs(g.fi);
        ans[g.se] = (res % 2);
        sum += res;
    }
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;
    P bombs[n];
    for (auto &bi:bombs) {
        cin >> bi.fi >> bi.se;
    }
    sort(bombs, bombs+n);
    bool prev = 0;
    for (int i=0; i<n; i++) {
        flip[i] = (bombs[i].se != prev);
        prev = bombs[i].se;
    }
    flip[n] = prev;
    for (int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;
        int ppl = partition_point(bombs, bombs+n, [&](P x) { return x.fi < l; }) - bombs,
            ppr = partition_point(bombs, bombs+n, [&](P x) { return x.fi <= r; }) - bombs;
        if (ppl == ppr) continue;
        G[ppl].push_back({ppr, i});
        G[ppr].push_back({ppl, i});
    }
    for (int i=0; i<=n; i++) {
        if (visited[i]) continue;
        if (dfs(i) % 2) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans.count() << '\n';
    for (int i=0; i<m; i++) {
        if (ans[i]) cout << i + 1 << ' ';
    }
    cout << '\n';
    return 0;
}