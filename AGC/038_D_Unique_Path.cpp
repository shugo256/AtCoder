#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

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
    int n, q;
    long m;
    cin >> n >> m >> q;
    vector<P> multis;
    uftree uft(n);
    for (int i=0, a, b, c; i<q; i++) {
        cin >> a >> b >> c;
        if (c)
            multis.push_back(P{a, b});
        else if (!uft.same(a, b)) {
            uft.unite(a, b);
            m--;
        }
    }
    long s = (long)uft.count_sets();
    long lim = s * (s-1) / 2;
    cerr << s << ' ' << multis.size() << ' ' << lim << ' ' << m << '\n';
    if ((s <= 2 && multis.size() > 0) || lim < (long)m || s-1 > (long)m) {
        cout << "No" << '\n';
        return 0;
    }
    set<int> roots;
    for (auto &p:multis) {
        if (!uft.same(p.fi, p.se)) {
            roots.insert(uft.root(p.fi));
            roots.insert(uft.root(p.se));
        } else {
            cout << "No" << '\n';
            return 0;
        }
    }
    if (roots.size() > 0 && (long)m < s) {
        cout << "No" << '\n';
        return 0;
    }
    cout << "Yes" << '\n';
    return 0;
}