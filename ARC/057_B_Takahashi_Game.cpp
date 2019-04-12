#include <cstdio>
#include <algorithm>

#define INF (int)1e9+1

using namespace std;

//どこが間違ってるのか不明だが、WA まじで原辰徳

int main() {
    int N, K, a, A, i, j;
    scanf("%d %d", &N, &K);
    int dp[N+1]; //dp[(i日のうち機嫌が良かった日数)] = (そうなるための勝利数の最小値)
    fill(dp, dp+N+1, INF);
    dp[0] = 0; dp[1] = 1; //i=1の状態
    scanf("%d", &A); //A=a1
    for (i=2; i<=N; i++) {
        scanf("%d",&a);
        for (j=i; j>=2; j--)
            if (dp[j-1] < A) //今まで全勝の場合(dp[j-1]=A)は翌日絶対に機嫌が悪いので更新する必要なし
                dp[j] = min(dp[j], dp[j-1] + (dp[j-1]*a)/A + 1);
        A += a;
    }
    for (j = N; dp[j] > K; j--);
    printf("%d\n",(K != A) ? j : 1);
    return 0;
}