#include <cstdio>

#define MAX_SUM 10000
#define MAX_N 100

using namespace std;

//Typical DP Contest
//改良版 一次元配列でよかったわい 768kb->128kb!!!

bool dp[MAX_SUM+1] = {0};

int main() {
    int N, p, i, j, count=0;
    scanf("%d",&N);
    dp[0] = true;
    for (i=0; i<N; i++) {
        scanf("%d",&p);
        for (j=100*i; j>=0; j--) if (dp[j]) dp[j+p] = true;
    }
    for (j=0; j<=100*N; j++) if (dp[j]) count++;
    printf("%d\n",count);
    return 0;
}