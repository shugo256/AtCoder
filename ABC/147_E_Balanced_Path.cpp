#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <bitset>

using ll = long long;

using namespace std;

#define MAX 6401
#define OFF 80

using B = bitset<MAX>;
B dp[81][81];

B rshift(B &bs, int n) {
    string s =bs.to_string().substr(MAX-n, n);
    reverse(s.begin(), s.end());
    return (bs >> n) | B(s + '0');
}

int main() {
    int h, w;
    cin >> h >> w;
    int dif[h][w];
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> dif[i][j];
        }
    }
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            int b;
            cin >> b;
            dif[i][j] = abs(dif[i][j] - b);
        }
    }
    dp[0][1][0] = dp[1][0][0] = true;
    for (int i=0; i<=h; i++) {
        for (int j=0; j<=w; j++) {
            // cerr << i << ' ' << j <<  ' ' << dp[i][j].to_string().substr(MAX-10, 10) << '\n';
            if (i < h && j > 0) dp[i+1][j] |= rshift(dp[i][j], dif[i][j-1]) | (dp[i][j] << dif[i][j-1]);
            if (j < w && i > 0) dp[i][j+1] |= rshift(dp[i][j], dif[i-1][j]) | (dp[i][j] << dif[i-1][j]);
        }
    }
    for (int i=0; i<MAX; i++) {
        if (dp[h][w][i]) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}