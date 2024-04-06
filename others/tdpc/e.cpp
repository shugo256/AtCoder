#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX_LEN 10001
#define MAX_D 100

using namespace std;

const int mod = (int)1e9 + 7;

int main() {
    int D, N, i, j, k, n, nextj;
    scanf("%d\n",&D);
    int dp[MAX_LEN+1][2][MAX_D] = {{{0}}};
    dp[0][0][0] = 1;
    for (i=1; (N = getchar()) != '\n' && N != EOF; i++) {
        n = N - '0';
        for (j=0; j<D; j++) {
            for (k=0; k<=9; k++) {
                nextj = (j+k)%D;
                if (k < n) {
                    dp[i][1][nextj] += (dp[i-1][0][j] + dp[i-1][1][j]) % mod;
                    dp[i][1][nextj] %= mod;
                } else if (k == n) {
                    dp[i][0][nextj] += dp[i-1][0][j];
                    dp[i][1][nextj] += dp[i-1][1][j];
                    dp[i][0][nextj] %= mod;
                    dp[i][1][nextj] %= mod;
                } else {
                    dp[i][1][nextj] += dp[i-1][1][j];
                    dp[i][1][nextj] %= mod;
                }
            }
        }
    }
    printf("%d\n", (dp[i-1][0][0] + dp[i-1][1][0] + mod-1) % mod); // -1は0のぶん
    return 0;
}