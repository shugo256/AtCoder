#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

using P = pair<long, long>;

struct edge {int i, j; long d;};

struct uftree {
    int *par, *rank, *size;
    uftree(int N) {
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
};

int main() {
    int n;
    cin >> n;
    P cities[n];
    for (auto &c: cities) cin >> c.first >> c.second;
    vector<int> xrank(n), yrank(n);
    iota(xrank.begin(), xrank.end(), 0);
    iota(yrank.begin(), yrank.end(), 0);
    sort(xrank.begin(), xrank.end(), [&](int l, int r) {
        return cities[l].first < cities[r].first;
    });
    sort(yrank.begin(), yrank.end(), [&](int l, int r) {
        return cities[l].second < cities[r].second;
    });
    vector<edge> es;
    int prev = -1;
    for (auto xr:xrank) {
        if (prev >= 0) {
            long d = cities[xr].first - cities[prev].first;
            es.push_back({prev, xr, d});
        }
        prev = xr;
    }
    prev = -1;
    for (auto yr:yrank) {
        if (prev >= 0) {
            long d = cities[yr].second - cities[prev].second;
            es.push_back({prev, yr, d});
        }
        prev = yr;
    }
    sort(es.begin(), es.end(), [](edge l, edge r) {
        return l.d < r.d;
    });
    uftree uft(n);
    long sum = 0;
    for (auto e:es) {
        if (uft.same(e.i, e.j)) continue;
        uft.unite(e.i, e.j);
        sum += e.d;
    }
    cout << sum << '\n';
    return 0;
}