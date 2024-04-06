#include <cstdio>
#include <algorithm>

#define INF 100000000

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    int a[A], b[B], sum=0;
    for (int i=A-1; i>=0; i--) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int j=B-1; j>=0; j--) {
        scanf("%d", &b[j]);
        sum += b[j];
    }
    int dp[A+1][B+1];
    dp[0][0] = 0;
    for (int i=0; i<=A; i++) {
        for (int j=0; j<=B; j++) {
            if (i == 0 && j == 0) continue;
            int n1 = i>0 ? a[i-1]-dp[i-1][j] : -INF;
            int n2 = j>0 ? b[j-1]-dp[i][j-1] : -INF;
            dp[i][j] = std::max(n1, n2);
        }
    }
    printf("%d\n", (sum + dp[A][B]) / 2);
    return 0;
}