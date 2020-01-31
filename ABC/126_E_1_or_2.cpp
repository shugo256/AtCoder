#include <iostream>
#include <algorithm>
#include <set>

#define MAX_N 100010

using namespace std;

struct uftree {
    int par[MAX_N], rank[MAX_N];
    uftree(int N) {
        for (int i=0; i<N; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }
    int root(int x) {
        return par[x] == x ? x : par[x] = root(par[x]); // 高速化ポイント
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
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    uftree uft(n);
    for (int i=0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        uft.unite(x, y);
    }
    set<int> s;
    for (int i=0; i<n; i++) 
        s.insert(uft.root(i));
    cout << s.size() << '\n';
    return 0;
}
