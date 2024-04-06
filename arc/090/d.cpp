#include <cstdio>

#define MAX_N 100000
#define INF 1000000000

struct uftree_w {
    int par[MAX_N], rank[MAX_N], w_dif[MAX_N]; //w_difは親との重みの差
    uftree_w(int N) {
        for (int i=0; i<N; i++) {
            par[i] = i;
            rank[i] = 0;
            w_dif[i] = 0;
        }
    }
    int root(int x) {
        if (par[x] == x)
            return x;
        else {
            int r = root(par[x]);
            w_dif[x] += w_dif[par[x]];
            return par[x] = r;
        }
    }
    int weight(int x) {
        root(x); //経路圧縮
        return w_dif[x];
    }
    bool unite(int x, int y, int d) {
        d += weight(x) - weight(y); //根っこ同士をつなぐので
        x = root(x);
        y = root(y);
        if (x == y) return d == 0;
        if (rank[x] > rank[y]) {
            par[y] = x;
            w_dif[y] = d;
        } else {
            par[x] = y;
            w_dif[x] = -d;
            if (rank[x] == rank[y]) rank[y]++;
        }
        return true;
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

int main() {
    int N, M, L, R, D;
    scanf("%d %d", &N, &M);
    uftree_w line(N);
    for (int i=0; i<M; i++) {
        scanf("%d %d %d", &L, &R, &D);
        if (!line.unite(L-1, R-1, D)) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}