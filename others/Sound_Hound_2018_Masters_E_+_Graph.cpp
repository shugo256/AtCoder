#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;

using namespace std;

using P = pair<int, ll>;
#define fi first
#define se second


struct node {
    // nodeに書く値はx + sig*t (tはノード0のあたい)
    ll x, sig;
    bool operator==(node n) {
        return x == n.x && sig == n.sig;
    }
};

bool visited[100010] = {0};
vector<P> G[100010];
node nodes[100010];


int dfs(int i=0) {
    visited[i] = true;
    for (auto &g:G[i]) {
        if (visited[g.fi]) {
            node n = {g.se - nodes[g.fi].x, -nodes[g.fi].sig};
            if (nodes[i] == n) continue;
            if ((nodes[i].x - n.x) % 2 == 0 && nodes[i].sig * n.sig != 0 && ((nodes[i].x <= n.x && nodes[i].sig > n.sig) || (nodes[i].x >= n.x && nodes[i].sig < n.sig))) {
                fill(begin(visited), end(visited), false);
                nodes[i] = {(nodes[i].x + n.x) / 2, 0};
                return (dfs(i) ? 1 : 0);
            }
            return 0;
        }
        nodes[g.fi] = {g.se - nodes[i].x, -nodes[i].sig};
        int ret = dfs(g.fi);
        if (ret < 2) return ret;
    }
    return 2;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0, u, v; i<m; i++) {
        ll s; cin >> u >> v >> s;
        u--; v--;
        G[u].push_back(P{v, s});
        G[v].push_back(P{u, s});
    }
    fill(begin(nodes), end(nodes), node{0, 1});
    ll l=1, r=999999999;
    if (dfs()) {
        for (int i=0; i<n; i++) {
            if (nodes[i].sig > 0) l = max(-nodes[i].x+1, l);
            else if (nodes[i].sig < 0) r = min(nodes[i].x-1, r);
            else if (nodes[i].x < 1) {
                cout << 0 << '\n';
                return 0;
            } else {
                l = r = 0;
            }
        }
        cout << max(0ll, r - l + 1) << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}