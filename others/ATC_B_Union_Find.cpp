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
    int N, Q, P, A, B;
    scanf("%d %d", &N, &Q);
    uftree T(N);
    for (int i=0; i<Q; i++) {
        scanf("%d %d %d", &P, &A, &B);
        if (P) printf("%s\n", T.same(A, B) ? "Yes" : "No");
        else T.unite(A, B);
    }
    return 0;
}