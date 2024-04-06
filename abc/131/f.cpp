#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

struct uftree {
    int *par, *rank, *size;
    uftree(int N) {
        par  = new int[(size_t)N];
        rank = new int[(size_t)N];
        size = new int[(size_t)N];
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
    int n, max = 100010;
    cin >> n;
    uftree uft(2*max + 1);
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        uft.unite(x, y+max);
    }
    unordered_map<int, long> xm, ym;
    for (int i=1; i<=2*max; i++) {
        int r = uft.root(i);
        if (i <= max)
            xm[r]++;
        else 
            ym[r]++;
    }
    long cnt = 0;
    for (auto xmi:xm) 
        cnt += xmi.second * ym[xmi.first];
    cout << cnt - n << '\n';
    return 0;
}
