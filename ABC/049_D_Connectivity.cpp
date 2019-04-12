#include <cstdio>
#include <utility>
#include <map>

#define MAX_N 200000

using namespace std;

typedef pair<int, int> P;

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
    int N, K, L, a, b;
    scanf("%d %d %d", &N, &K, &L);
    uftree road(N), rail(N);
    for (int i=0; i<K+L; i++) {
        scanf("%d %d", &a, &b);
        if (i < K) road.unite(a-1, b-1);
        else rail.unite(a-1, b-1);
    }
    P roots[N];
    map<P, int> ans;
    for (int i=0; i<N; i++) {
        roots[i] = {road.root(i), rail.root(i)};
        ans[roots[i]]++;
    }
    for (int i=0; i<N; i++) printf("%d ", ans[roots[i]]);
    printf("\n");
    return 0;
}