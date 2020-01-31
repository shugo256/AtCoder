#include <iostream>
#include <algorithm>
#include <string>

#define mod (long)(1e9 + 7)

using namespace std;

int main() {
    string s;
    cin >> s;
    long dp[4] = {1, 0, 0, 0};
    for (auto c:s) {
        if (c == '?') {
            for (int i = 3; i >= 0; i--) {
                if (i <= 2)
                    dp[i + 1] = (dp[i] + dp[i + 1]) % mod;
                dp[i] = (dp[i] * 3) % mod;
            }
        } else {
            int j = c - 'A';
            dp[j+1] = (dp[j] + dp[j+1]) % mod;
        }
    }
    cout << dp[3] << '\n';
    return 0;
}