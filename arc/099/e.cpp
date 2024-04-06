#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <bitset>

using ll = long long;

using namespace std;

struct uftree {
    int n, *par, *rank, *size;
    uftree(int N) : n(N) {
        par = new int[(size_t)N];
        rank = new int[(size_t)N];
        size = new int[(size_t)N];
        for (int i = 0; i < N; i++) {
            par[i]  = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
    int root(int x) {
        if (par[x] == x)
            return x;
        else {
            int r         = root(par[x]);
            size[x]       = size[par[x]];
            return par[x] = r;
        }
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (rank[x] > rank[y])
            par[y] = x;
        else {
            par[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        }
        size[x] += size[y];
        size[y] = size[x];
    }
    int get_size(int x) {
        root(x);
        return size[x];
    }
    bool same(int x, int y) { return root(x) == root(y); }

    // 集合の数をカウントする関数
    // 1..nのつもりでやってる場合も0をカウントしちゃうので注意
    int count_sets() {
        int cnt = 0;
        bool used[n];
        fill(used, used+n, false);
        for (int i=0; i<n; i++) {
            if (used[root(i)]) continue;
            cnt++;
            used[root(i)] = true;
        }
        return cnt;
    }
};

vector<int> G[710];
int color[710] = {0};

bool dfs(int i, int c=1) {
    color[i] = c;
    for (auto &g:G[i]) {
        if ((color[g] && color[i] == color[g]) || (!color[g] && !dfs(g, c ^ 3)))
            return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    bool connect[n][n];
    fill(connect[0], connect[n], true);
    for (int i=0, a, b; i<m; i++) {
        cin >> a >> b;
        a--; b--;
        connect[a][b] = connect[b][a] = false;
    }
    uftree uft(n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (!connect[i][j]) continue;
            G[i].push_back(j);
            G[j].push_back(i);
            uft.unite(i, j);
        }
    }
    set<int> pars;
    for (int i=0; i<n; i++)
        pars.insert(uft.root(i));
    for (auto &p:pars) {
        if (!dfs(p)) {
            cout << -1 << '\n';
            return 0;
        }
    }
    int red[n];
    fill(red, red+n, 0);
    for (int i=0; i<n; i++) if (color[i] == 1) red[uft.root(i)]++;
    bitset<701> bs;
    bs.set(0);
    for (auto &p:pars) {
        bs = (bs << red[p]) | (bs << (uft.get_size(p) - red[p]));
    }
    int ans = n * (n-1) / 2;
    for (int i=0; i<=n; i++) {
        if (bs[i]) {
            ans = min(ans, i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2);
        }
    }
    cout << ans << '\n';
    return 0;
}