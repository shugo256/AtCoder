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

using P = pair<ll, ll>;
#define fi first
#define se second

int main() {
    int n;
    cin >> n;
    P a[n], b[n];
    for (int i=0; i<n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    for (int i=0; i<n; i++) {
        cin >> b[i].fi;
        b[i].se = i;
    }
    sort(a, a+n);
    sort(b, b+n);
    bool yes = false;
    uftree uft(n);
    for (int i=0; i<n; i++) {
        auto lb = partition_point(a, a+n, [&](P ai) {
            return ai.fi <= b[i].fi;
        });
        int j = lb - a - 1;
        if (j < i) {
            cout << "No" << '\n';
            return 0;
        }
        else if (j > i || (i < n-1 && uft.same(a[j].se, b[i].se))) {
            yes = true;
        }
        uft.unite(a[j].se, b[i].se);
    }
    cout << (yes ? "Yes" : "No") << '\n';
    return 0;
}