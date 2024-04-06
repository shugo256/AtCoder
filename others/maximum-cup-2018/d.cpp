#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int N, M, L, X, a, i, j;
    scanf("%d %d %d %d\n", &N, &M, &L, &X);
    int dp[2][M];
    fill_n(dp[0], 2*M, X);
    dp[0][0] = 0; dp[1][0] = 0;
    for (i=0; i<N; i++) {
        scanf("%d",&a);
        for (j=0; j<M; j++) {
            if (dp[0][j] < X) {
                const int sum = a + dp[0][j]*M + j;
                dp[1][sum%M] = min(sum/M, dp[0][sum%M]); //商を保存
            }
        }
        if (dp[1][L] < X) {
            printf("Yes\n");
            return 0;
        }
        for (j=0; j<M; j++) dp[0][j] = dp[1][j];
    }
    printf("No\n");
    return 0;
}