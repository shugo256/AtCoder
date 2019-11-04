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

struct brother {int x, y, z, l, r;};

int main() {
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    for (int i=0; i<m; i++) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    queue<int> waiting[m];
    int q; cin >> q;
    brother bros[q];
    for (int i=0; i<q; i++) {
        cin >> bros[i].x >> bros[i].y >> bros[i].z;
        bros[i].x--; bros[i].y--;
        bros[i].l = -1; bros[i].r = m-1;
        waiting[m / 2].push(i);
    }
    int cnt = 0;
    while (cnt < q) {
        uftree uft(n);
        for (int i=0; i<m; i++) {
            uft.unite(a[i], b[i]);
            while (!waiting[i].empty()) {
                int f = waiting[i].front(); waiting[i].pop();
                brother &br = bros[f];
                int score = uft.get_size(br.x) + (uft.same(br.x, br.y) ? 0 : uft.get_size(br.y));
                //cerr << f << ' ' << i << ' ' << score << ' ' << uft.get_size(br.x) << ' ' << uft.get_size(br.y) << ' ' << uft.same(br.x, br.y) << '\n';
                if (score >= br.z) br.r = i;
                else br.l = i;
                if (br.l + 1 < br.r) 
                    waiting[(br.l + br.r + 1)/2].push(f);
                else 
                    cnt++;
            }
        }
    }
    for (auto &br:bros) cout << br.r + 1 << '\n';
    return 0;
}