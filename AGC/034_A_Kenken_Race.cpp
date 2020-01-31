#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define MAX_N 200010

using namespace std;

struct uftree {
    int par[MAX_N], rank[MAX_N], size[MAX_N];
    uftree(int N) {
        for (int i = 0; i < N; i++) {
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
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    a--; b--; c--; d--;
    uftree uft(n);
    int scnt=0, rcnt=0, i=0, prev = -1;
    vector<int> trees;
    for (auto si:s) {
        if (si == '.') {
            scnt++;
            if (scnt == 3) trees.push_back(i);
            if (rcnt <= 1 && prev >= 0) uft.unite(prev, i);
            rcnt = 0;
            prev = i;
        } else {
            scnt=0;
            rcnt++;
        }
        // cerr << scnt << ' ' << rcnt << ' ' << prev << '\n';
        i++;
    }
    // for (auto t:trees) cerr << t << ' ' << uft.same(t, a) << '\n';
    if (uft.same(a, c) && uft.same(b, d)) {
        if (c < d) {
            cout << "Yes" << '\n';
            return 0;
        }
        for (auto t:trees) {
            if (uft.same(a, t) && b <= t-1 && t-1 <= d) {
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}
