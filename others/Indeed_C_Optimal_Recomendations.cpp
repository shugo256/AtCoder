#include <cstdio>
#include <algorithm>

#define MAX_SCORE 100

using namespace std;

int main() 
{
    int N, M, a, b, c, w, i;
    int dp[MAX_SCORE+1][MAX_SCORE+1][MAX_SCORE+1] = {{{0}}};
    scanf("%d %d",&N,&M);
    for (i=0; i<N; i++) {
        scanf("%d %d %d %d",&a,&b,&c,&w);
        if (dp[a][b][c] < w) {
            dp[a][b][c] = w;
        }
    }
    for (a=0; a<=100; a++) {
        for (b=0; b<=100; b++) {
            for (c=0; c<=100; c++) {
                int dp111 = dp[a][b][c];
                int dp011 = (a>0) ? dp[a-1][b][c] : 0;
                int dp101 = (b>0) ? dp[a][b-1][c] : 0;
                int dp110 = (c>0) ? dp[a][b][c-1] : 0;
                dp[a][b][c] = max({dp111,dp011,dp101,dp110});
            }
        }
    }
    for (i=0; i<M; i++) {
        scanf("%d %d %d",&a,&b,&c);
        printf("%d\n",dp[a][b][c]);
    }
    return 0;
}