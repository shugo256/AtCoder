#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>

#define all(vec) vec.begin(), vec.end()

using namespace std;

struct point{long x, y;};

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
    int getsize(int x) {
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
            if (used[par[i]]) continue;
            cnt++;
            used[par[i]] = true;
        }
        return cnt;
    }
};

#define MAX_N 100010
struct edge{int from, to; long cost;};
int n;
vector<edge> E;
long kruscal() {
    uftree uft(n);
    sort(all(E), [](edge l, edge r) {
        return l.cost < r.cost;
    });
    long sum = 0;
    for (auto e:E) {
        if (uft.same(e.from, e.to)) continue;
        sum += e.cost;
        uft.unite(e.from, e.to);
    }
    return sum;
}

int main() {
    cin >> n;
    point p[n];
    for (auto &pi:p) 
        cin >> pi.x >> pi.y;
    int xs[n], ys[n];
    iota(xs, xs+n, 0);
    iota(ys, ys+n, 0);
    sort(xs, xs+n, [&](int l, int r) {
        return p[l].x < p[r].x;
    });
    sort(ys, ys+n, [&](int l, int r) {
        return p[l].y < p[r].y;
    });
    for (int i=0; i<n-1; i++) {
        E.push_back({xs[i], xs[i+1], p[xs[i+1]].x - p[xs[i]].x});
        E.push_back({ys[i], ys[i+1], p[ys[i+1]].y - p[ys[i]].y});
    }
    cout << kruscal() << '\n';
    return 0;
}

