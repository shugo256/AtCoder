#include <cstdio>

#define MAX_N 100000

struct uftree {
    int par[MAX_N], rank[MAX_N];
    uftree(int N) {
        for (int i=0; i<N; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }
    int root(int x) {
        return par[x] == x ? x : par[x] = root(par[x]);
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
    int N, M;
    scanf("%d %d", &N, &M);
    int p, x, y, pinv[N];
    for (int i=0; i<N; i++) {
        scanf("%d", &p);
        pinv[p-1] = i;
    }
    uftree T(N);
    for (int i=0; i<M; i++) {
        scanf("%d %d", &x, &y);
        T.unite(x-1, y-1);
    }
    int ans=0;
    for (int i=0; i<N; i++) if (T.same(i, pinv[i])) ans++;
    printf("%d\n", ans);
    return 0;
}