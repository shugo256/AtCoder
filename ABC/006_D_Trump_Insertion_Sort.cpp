#include <cstdio>
#include <algorithm>

#define INF 100000

using namespace std;

int main() {
    int N, c;
    scanf("%d", &N);
    int dp[N];
    fill(dp, dp+N, INF);
    for (int i=0; i<N; i++) {
        scanf("%d", &c);
        int a = 0, b = N;
        while (b-a > 1) {
            int cen = (a+b)/2;
            if (c < dp[cen]) b = cen;
            else a = cen;
        }
        if (c < dp[a]) dp[a] = c;
        else if (c < dp[a+1]) dp[a+1] = c;
    }
    printf("%ld\n", dp+N - lower_bound(dp, dp+N, INF));
    return 0;
}