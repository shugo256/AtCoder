#include <cstdio>
#include <algorithm>
#define mod (long)(1e9+7)

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    long dp[101][4][4][4] = {{{{0}}}}; //T0 A1 G2 C3とした4進数
    dp[0][0][0][0] = 1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<4; k++) {
                for (int l=0; l<4; l++) {
                    dp[i+1][k][l][0] = (dp[i+1][k][l][0] + dp[i][j][k][l]) % mod; //T
                    dp[i+1][k][l][1] = (dp[i+1][k][l][1] + dp[i][j][k][l]) % mod; //A
                    if (k != 1 || l != 3) //ACG
                        dp[i+1][k][l][2] = (dp[i+1][k][l][2] + dp[i][j][k][l]) % mod; //G
                    if ((l != 2 || (j != 1 && k != 1)) && (k != 2 || (j != 1 && l != 1)))
                        dp[i+1][k][l][3] = (dp[i+1][k][l][3] + dp[i][j][k][l]) % mod; //C
                }
            }
        }
    }
    long sum=0;
    for (int j=0; j<4; j++) {
        for (int k=0; k<4; k++) {
            for (int l=0; l<4; l++) {
                sum = (sum + dp[N][j][k][l]) % mod;
            }
        }
    }
    printf("%ld\n", sum);
    return 0;
}