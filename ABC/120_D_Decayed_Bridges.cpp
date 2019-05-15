#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 100010
#define range(vec) vec.begin(), vec.end()
#define rrange(vec) vec.rbegin(), vec.rend()

using namespace std;

typedef pair<int, int> P;

struct uftree {
    int par[MAX_N], rank[MAX_N], size[MAX_N];
    uftree(int N) {
        for (int i=0; i<N; i++) {
            par[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
    int root(int x) {
        if (par[x] == x)
            return x;
        else {
            int r = root(par[x]);
            size[x] = size[par[x]];
            return par[x] = r;
        }
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (rank[x] > rank[y]) par[y] = x;
        else {
            par[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        }
        size[x] += size[y];
        size[y] = size[x];
    }
    int tsize(int x) {
        root(x);
        return size[x];
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

int main() {
    size_t n, m;
    cin >> n >> m;
    vector<P> ab(m);
    for (auto &p:ab)
        cin >> p.first >> p.second;
    uftree uft((int)n);
    long scores[m];
    scores[m-1] = n * (n-1) / 2;
    for (size_t i=m-1; i>0; i--) {
        int a = ab[i].first-1, b = ab[i].second-1;
        if (!uft.same(a, b)) {
            long as = uft.tsize(a), bs = uft.tsize(b);
            scores[i-1] = scores[i] - as * bs;
            uft.unite(a, b);
        } else 
            scores[i-1] = scores[i];
    }
    for (auto s:scores)
        cout << s << '\n';
    return 0;
}