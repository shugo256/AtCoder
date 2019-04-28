#include <cstdio>
#include <algorithm>
#include <functional>

#define mod (long)(1e9+7)
#define MAX_X 100010

using namespace std;

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int s[n];
    long dp[x+1];
    fill(dp, dp+x+1, 0);
    dp[x] = 1;
    for (int i=0; i<n; i++) scanf("%d", s+i);
    sort(s, s+n, greater<int>());
    for (int i=0; i<n; i++) {
        for (int j=0; j<=x; j++) {
            if (dp[j] == 0) continue;
            dp[j%s[i]] = (dp[j%s[i]] + dp[j]) % mod;
            if (i == n-1 && j >= s[i]) dp[j] = 0;
        }
    }
    long sum = 0;
    for (int j=0; j<s[n-1]; j++) {
        sum = (dp[j] * j + sum) % mod;
        printf("%ld\n", dp[j]);
    }
    printf("%ld\n", sum);
    return 0;
}