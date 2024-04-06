#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int dp[3001][3] = {{0}};
    int sum=0;
    dp[0][0] = 1;
    for (int i=0; i<N; i++) {
        for (int j=N; j>=0; j--) {
            if (j + R <= N) dp[j + R][0] = dp[j][0];
            if (j + G <= N) dp[j + G][1] = dp[j][0] + dp[j][1];
            if (j + B <= N) dp[j + B][2] = dp[j][0] + dp[j][1] + dp[j][2];
            dp[j][0] = 0; dp[j][1] = 0; dp[j][2] = 0;
        }
        sum += dp[N][0] + dp[N][1] + dp[N][2];
    }
    cout << sum << '\n';
    return 0;
}
