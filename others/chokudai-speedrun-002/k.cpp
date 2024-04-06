#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

#define MAX_N 500000

using namespace std;

struct uftree {
    int par[MAX_N], rank[MAX_N], size[MAX_N], edges[MAX_N];
    uftree(int N) {
        for (int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
            size[i] = 1;
            edges[i] = 0;
        }
    }
    int root(int x) {
        if (par[x] == x)
            return x;
        else {
            int r = root(par[x]);
            size[x] = size[par[x]];
            edges[x] = edges[par[x]];
            return par[x] = r;
        }
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) {
            edges[x]++;
            return;
        }
        if (rank[x] > rank[y])
            par[y] = x;
        else {
            par[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        }
        size[x] += size[y];
        size[y] = size[x];
        edges[x] += edges[y] + 1;
        edges[y] = edges[x];
    }
    int getsize(int x) {
        root(x);
        return size[x];
    }
    int getedges(int x) {
        root(x);
        return edges[x];
    }
    bool same(int x, int y) { return root(x) == root(y); }
};

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> um;
    uftree uft(500000);
    int cnt = 1;
    for (int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        if (um[a] == 0) {
            um[a] = cnt;
            cnt++;
        }
        if (um[b] == 0) {
            um[b] = cnt;
            cnt++;
        }
        uft.unite(um[a], um[b]);
    }
    int sum = 0;
    bool used[500000];
    fill(used, used+cnt, false);
    for (int i=1; i<cnt; i++) {
        int ri = uft.root(i);
        if (used[ri]) continue;
        sum += min(uft.getsize(ri), uft.getedges(ri));
        used[ri] = true;
    }
    cout << sum << '\n';
    return 0;
}
