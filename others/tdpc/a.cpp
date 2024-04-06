#include <cstdio>

#define MAX_SUM 10000
#define MAX_N 100

using namespace std;

//Typical DP Contest

bool dp[MAX_N+1][MAX_SUM+1] = {{0}};

int main() {
    int N, p, i, j, count=0;
    scanf("%d",&N);
    dp[0][0] = true;
    for (i=0; i<N; i++) {
        scanf("%d",&p);
        for (j=0; j<=100*i; j++) {
            if (dp[i][j]) {
                dp[i+1][j] = true;
                dp[i+1][j+p] = true;
            }
        }
    }
    for (j=0; j<=100*N; j++) if (dp[N][j]) count++;
    printf("%d\n",count);
    return 0;
}