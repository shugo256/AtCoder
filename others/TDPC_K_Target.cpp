#include <cstdio>
#include <algorithm>
#include <functional>

#define INF 1000000000

using namespace std;

struct circ {
    int a;
    int b;
};

bool bcomp(const circ& left, const circ& right) {
    return left.b < right.b || (left.b == right.b && left.a < right.a);
}

int main() {
    int N, x, r;
    scanf("%d", &N);
    circ C[N];
    for (int i=0; i<N; i++) {
        scanf("%d%d", &x, &r);
        C[i].a = x-r;
        C[i].b = x+r;
    }
    sort(C, C+N, bcomp);
    int dp[N];
    fill(dp, dp+N, -INF);
    for (int i=0; i<N; i++) {
        *lower_bound(dp, dp+N, C[i].a, greater<int>()) = C[i].a;
    }
    printf("%ld\n", lower_bound(dp, dp + N, -INF, greater<int>()) - dp);
    return 0;
}