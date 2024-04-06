#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define amax(a, b) a = max(a, b)
#define INF 1e15

int main() {
    int n;
    cin >> n;
    int k = n / 2;
    ll a[n]; for (auto &ai:a) cin >> ai;
    ll dp[k + 1][3];
    fill(dp[0], dp[k+1], -INF);
    dp[0][0] = 0;
    for (int i=0; i<k; i++) {
        for (int x=0; x<3; x++) {
            for (int y=x; y<3; y++) {
                if (i*2 + y < n)
                    amax(dp[i+1][y], dp[i][x] + a[i*2 + y]);
            }
        }
    }
    cout << max({dp[k][0], dp[k][1], dp[k][2]}) << '\n';
    return 0;
}