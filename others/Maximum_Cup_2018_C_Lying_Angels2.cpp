#include <cstdio>

#define MAX_N 100000

// union find 木による高速化ver

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
        return par[x] == x ? x : par[x] = root(par[x]); // 高速化ポイント
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (rank[x] > rank[y]) {
            par[y] = x;
            size[x] += size[y];
        } else {
            par[x] = y;
            size[y] += size[x];
            if (rank[x] == rank[y]) rank[y]++;
        }
    }
    bool oddsize(int x) {
        return size[root(x)]%2;
    }
};

int main() {
    int N, A;
    scanf("%d", &N);
    uftree T(N);
    for (int i=0; i<N; i++) {
        scanf("%d", &A);
        T.unite(i,A-1);
    }
    for (int i=0; i<N; i++) {
        if (T.oddsize(i)) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", N/2);
    return 0;
}