#include <iostream>
#include <algorithm>
#include <vector>

#define maxing(a, b) a = max(a, b)

using namespace std;

int main() {
    int n;
    long x;
    cin >> n >> x;
    vector<vector<long>> dp(n, vector<long>(n, 0));
    long t[n];
    int next[n];
    int j=0;
    for (int i=0; i<n; i++) {
        cin >> t[i];
        while (t[i] > t[j] + x) {
            next[j] = i;
            j++;
        }
    }
    for ( ; j<n; j++) next[j] = n;
    dp[0][0] = x;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i < n-1)
                maxing(dp[i+1][j], dp[i][j]);
            if (j < n-1) {
                maxing(dp[next[i] - 1][j+1], dp[i][j] + t[next[i] - 1] - t[i]);
                if (next[i] < n) 
                    maxing(dp[next[i]][j+1], dp[i][j] + x);
            }
        }
    }
    for (auto &ansi:dp[n-1]) cout << ansi << '\n';
    return 0;
}