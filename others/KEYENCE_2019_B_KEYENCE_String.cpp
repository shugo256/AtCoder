#include <cstdio>
#include <cstring>

#define MAX_LEN 100

using namespace std;

int main() {
    int c, i, j=0;
    char T[] = "keyence_";
    bool dp[8][3][MAX_LEN+1] = {{{0}}};
    dp[0][0][0] = true;
    while ((c = getchar()) >= 'a' && c <= 'z') {
        for (i = 0; i < 8; i++) {
            dp[i][1][j+1] = dp[i][0][j] || dp[i][1][j];
            if (c == (int)T[i]) {
                dp[i+1][0][j+1] = dp[i][0][j];
                dp[i+1][2][j+1] = dp[i][1][j] || dp[i][2][j];
            }
        }
        j++;
    }
    if (dp[7][0][j] || dp[7][1][j] || dp[7][2][j]) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}