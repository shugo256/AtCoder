#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

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

using P = pair<int, int>;
#define fi first
#define se second

int main() {
    long n, m, W;
    cin >> n >> m >> W;
    long w[n], v[n];
    for (int i=0; i<n; i++)
        cin >> w[i] >> v[i];
    uftree uft(n);
    for (int i=0, a, b; i<m; i++) {
        cin >> a >> b;
        a--; b--;
        uft.unite(a, b);
    }
    int ids[n];
    fill(ids, ids+n, -1);
    vector<P> naps;
    for (int i=0; i<n; i++) {
        int r = uft.root(i);
        if (ids[r] == -1) {
            ids[r] = naps.size();
            naps.push_back({0, 0});
        }
        naps[ids[r]].fi += w[i];
        naps[ids[r]].se += v[i];
    }
    int len = naps.size();
    long dp[len+1][W+1];
    fill(dp[0], dp[len+1], 0);
    for (int i=0; i<len; i++) {
        long wi = naps[i].fi, vi = naps[i].se;
        for (int j=0; j<=W; j++) {
            dp[i+1][j] = dp[i][j];
            if (j > 0)
                dp[i+1][j] = max(dp[i+1][j], dp[i+1][j-1]);
            if (j >= wi)
                dp[i+1][j] = max({dp[i+1][j], dp[i][j-wi] + vi});
        }
    }
    cout << dp[len][W] << '\n';
    return 0;
}