#include <cstdio>
#include <algorithm>

// 未解決！！！

#define mod (long)(1e9 + 7)
#define MAX_N 100
#define MAX_SUM 1000

using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int kill, A=0, B=0;
    int ia
    for (int i=0; i<N+M; i++) {
        scanf("%d", &kill);
        if (i < N) A += kill;
        else B += kill;
    }
    long dp[MAX_N + 1][MAX_SUM + 1] = {{0}};
    dp[0][0] = 1;
    int nm = max(N, M), ab = max(A, B);
    for (int i=1; i<=nm; i++) {
        for (int j=0; j<=ab; j++) {
            dp[i][j] = (dp[i-1][j] + (j-i>=0 ? dp[i][j-i] : 0)) % mod;
            printf("%d %d %ld %ld %ld\n", i, j, dp[i-1][j], j-i>=0 ? dp[i][j-i] : 0, dp[i][j]);
        }
    }
    printf("%d %d %ld; %d %d %ld\n", N, B, dp[N][B], M, A, dp[M][A]);
    printf("%ld\n", dp[N][B]*dp[M][A]%mod);
    return 0;
}