#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 100

using namespace std;

typedef long long ll;

int main() {
    int N, t, i, j, k, d2=0, d3=0, d5=0;
    ll D;
    scanf("%d %lld", &N, &D);
    for ( ; D%2 == 0; D/=2) d2++;
    for ( ; D%3 == 0; D/=3) d3++;
    for ( ; D%5 == 0; D/=5) d5++;
    if (D > 1) {
        printf("0\n");
        return 0;
    }
    double dp[N+1][d2+1][d3+1][d5+1];
    memset(dp,0,sizeof(dp));
    dp[0][0][0][0] = 1;
    for (t=0; t<N; t++) {
        for (i=0; i<=d2; i++) {
            for (j=0; j<=d3; j++) {
                for (k=0; k<=d5; k++) {
                    const double dpijk = dp[t][i][j][k];
                    if(dpijk==0) continue;
                    const int i1=min(i+1,d2), i2=min(i+2,d2), j1=min(j+1,d3), k1=min(k+1,d5);
                    dp[t+1][i ][j ][k ] += dpijk/6; //1
                    dp[t+1][i1][j ][k ] += dpijk/6; //2
                    dp[t+1][i ][j1][k ] += dpijk/6; //3
                    dp[t+1][i2][j ][k ] += dpijk/6; //4
                    dp[t+1][i ][j ][k1] += dpijk/6; //5
                    dp[t+1][i1][j1][k ] += dpijk/6; //6
                }
            }
        }
    }
    printf("%.10f\n",dp[N][d2][d3][d5]);
    return 0;
}