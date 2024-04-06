#include <cstdio>
#include <algorithm>
#include <cmath>

int main() {
    int N, n=(int)1e8, d=0;
    scanf("%d", &N);
    int dp[10][2][8] = {{{0}}}; //less, {3?, 5?, 7?}(2)
    int j5[] = {0,1,4,5};
    bool zero = true, tookoff = false;
    for (int i=0; i<9; i++) {
        d = d*10 + N/n;
        N = N%n;
        n /= 10;
        for (int j=0; j<8; j+=2) {
            if (d > 3)
                dp[i+1][1][j+1] += dp[i][0][j] + dp[i][0][j+1];
            else if (d == 3)
                dp[i+1][0][j+1] += dp[i][0][j] + dp[i][0][j+1] + ((zero && j==0) ? 1 : 0);
            dp[i+1][1][j+1] += dp[i][1][j] + dp[i][1][j+1] + ((d > 3 || !zero) && j == 0 ? 1 : 0);
        }
        for (int k = 0; k < 4; k++) {
            if (d > 5)
                dp[i+1][1][j5[k]+2] += dp[i][0][j5[k]] + dp[i][0][j5[k]+2];
            else if (d == 5)
                dp[i+1][0][j5[k]+2] += dp[i][0][j5[k]] + dp[i][0][j5[k]+2] + ((zero && k==0) ? 1 : 0);
            dp[i+1][1][j5[k]+2] += dp[i][1][j5[k]] + dp[i][1][j5[k]+2] + ((d > 5 || !zero) && k == 0 ? 1 : 0);
        }
        for (int j = 0; j < 4; j++) {
            if (d > 7)
                dp[i+1][1][j+4] += dp[i][0][j] + dp[i][0][j+4];
            else if (d == 7)
                dp[i+1][0][j+4] += dp[i][0][j] + dp[i][0][j+4] + ((zero && j==0) ? 1 : 0);
            dp[i+1][1][j+4] += dp[i][1][j] + dp[i][1][j+4] + ((d > 7 || !zero) && j == 0 ? 1 : 0);
        }
        if (zero && d != 0) zero = false;
        if (!tookoff && d >= 3) tookoff = true;
        if (tookoff) d = 0;
    }
    printf("%d\n", dp[9][0][7] + dp[9][1][7]);
    return 0;
}