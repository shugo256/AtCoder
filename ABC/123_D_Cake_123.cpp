#include <cstdio>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

struct cakes {
    long sum;
    int ia;
    int ib;
    int ic;
};

bool operator < (const cakes& left, const cakes& right) {
    return left.sum < right.sum || (left.sum == right.sum && (left.ia > right.ia || (left.ia == right.ia && (left.ib > right.ib || (left.ib == right.ib && left.ic > right.ic)))));
}

int main() {
    int x, y, z, k;
    scanf("%d %d %d %d", &x, &y, &z, &k);
    long a[x], b[y], c[z];
    for (int i=0; i<x; i++) scanf("%ld", a+i);
    for (int i=0; i<y; i++) scanf("%ld", b+i);
    for (int i=0; i<z; i++) scanf("%ld", c+i);
    sort(a, a+x, greater<long>());
    sort(b, b+y, greater<long>());
    sort(c, c+z, greater<long>());
    priority_queue<cakes> pq;
    int na=-1, nb=-1, nc=-1;
    pq.push(cakes({a[0]+b[0]+c[0], 0, 0, 0}));
    for (int i=0; i<k; i++) {
        cakes now = pq.top(); pq.pop();
        while (na == now.ia && nb == now.ib && nc == now.ic) {
            now = pq.top(); pq.pop();
        }
        na = now.ia; nb = now.ib; nc = now.ic;
        printf("%ld\n", now.sum);
        if (na + 1 < x) pq.push(cakes({a[na+1]+b[nb]+c[nc], na+1, nb, nc}));
        if (nb + 1 < y) pq.push(cakes({a[na]+b[nb+1]+c[nc], na, nb+1, nc}));
        if (nc + 1 < z) pq.push(cakes({a[na]+b[nb]+c[nc+1], na, nb, nc+1}));
    }
    return 0;
}