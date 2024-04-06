#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 50

int main() {
    int W, N, K, i, w, k;
    scanf("%d",&W);
    scanf("%d %d", &N, &K);
    fflush(stdout);
    int A, B, dp[W+1][K+1];
    memset(dp,0,sizeof(dp));
    for (i=0; i<N; i++) {
        scanf("%d %d", &A, &B);
        for (w=W; w>=0; w--) {
            for (k=K; k>=0; k--) {
                if (w>=A && k>=1) dp[w][k] = std::max(dp[w-A][k-1]+B,dp[w][k]);
            }
        }
    }
    printf("%d\n",dp[W][K]);
}