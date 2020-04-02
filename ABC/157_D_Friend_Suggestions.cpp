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
    int n, m, k;
    cin >> n >> m >> k;
    uftree uft(n);
    vector<P> friends;
    for (int i=0, a, b; i<m; i++) {
        cin >> a >> b;
        uft.unite(--a, --b);
        friends.push_back({a, b});
    }
    int candi[n];
    for (int i=0; i<n; i++) candi[i] = uft.get_size(i) - 1;
    for (auto &f:friends) candi[f.fi]--, candi[f.se]--;
    for (int i=0, c, d; i<k; i++) {
        cin >> c >> d;
        if (uft.same(--c, --d)) {
            candi[c]--;
            candi[d]--;
        }
    }
    for (int i=0; i<n; i++) {
        cout << candi[i] << (i < n-1 ? ' ' : '\n');
    }
    return 0;
}