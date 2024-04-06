#include <cstdio>
#include <algorithm>

#define INF 100000000000

using namespace std;

int main() {
    int A, B, Q;
    scanf("%d %d %d", &A, &B, &Q);
    long s[A], t[B], x;
    for (int i=0; i<A+B; i++) {
        if (i<A) scanf("%ld", &s[i]);
        else scanf("%ld", &t[i-A]);
    }
    for (int i=0; i<Q; i++) {
        scanf("%ld", &x);
        int is = upper_bound(s, s+A, x) - s, it = upper_bound(t, t+B, x) - t;
        long es = is > 0 ? x - s[is-1] : INF,  ws = is < A ? s[is] - x : INF,
             et = it > 0 ? x - t[it-1] : INF,  wt = it < B ? t[it] - x : INF;
        long best = min(min(max(es,et), max(ws,wt)), min(min(es,wt)+es+wt, min(ws,et)+ws+et));
        printf("%ld\n" ,best);
    }
    return 0;
}