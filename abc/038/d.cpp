#include <cstdio>
#include <algorithm>

#define INF 1000000

using namespace std;

struct box {
    int w;
    int h;
};

bool wcomp(const box& left, const box& right) {
    return left.w < right.w || (left.w == right.w && left.h > right.h);
}

int main() {
    int N;
    scanf("%d", &N);
    box B[N];
    for (int i=0; i<N; i++) scanf("%d %d", &B[i].w, &B[i].h);
    sort(B, B+N, wcomp);
    int dp[N];
    fill(dp, dp+N, INF);
    for (int i=0; i<N; i++) {
        *lower_bound(dp, dp+N, B[i].h) = B[i].h;
    }
    printf("%ld\n", lower_bound(dp, dp+N, INF) - dp);
    return 0;
}