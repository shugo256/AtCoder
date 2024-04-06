#include <iostream>
#include <algorithm>

#define INF 5000

using namespace std;

int main() {
    int n, ma, mb;
    cin >> n >> ma >> mb;
    int dp[500][500];
    fill(dp[0], dp[500], INF);
    dp[0][0] = 0;
    for (int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j=500; j>=0; j--) {
            if (j + a >= 500) continue;
            for (int k=500; k>=0; k--) {
                if (k + b >= 500) continue;
                dp[j+a][k+b] = min(dp[j+a][k+b], dp[j][k] + c);
            }
        }
    }
    int res = INF;
    //for (auto &dpi:dp) {for (auto &dpij:dpi) cerr << dpij << ' '; cerr <<  endl;}
    for (int i=1; ma * i < 500 && mb * i < 500; i++)
        res = min(res, dp[ma*i][mb*i]);
    cout << (res < INF ? res : -1) << '\n';
    return 0;
}