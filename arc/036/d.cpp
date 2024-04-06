#include <cstdio>

#define MAX_N 100000

// 撤退！！！！！！！！

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
    int N, Q, w, x, y, z;
    scanf("%d %d", &N, &Q);
    uftree even(N), odd(N);
    for (int i=0; i<Q; i++) {
        scanf("%d %d %d %d", &w, &x, &y, &z);
        x--; y--;
        if (w == 2) printf("%s\n", even.same(x, y) ? "YES" : "NO");
        else {
            if (z%2 == 0 || odd.same(x, y)) even.unite(x, y);
            odd.unite(x, y);
        }
    }
    return 0;
}