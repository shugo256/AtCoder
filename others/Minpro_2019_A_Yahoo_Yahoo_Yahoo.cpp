#include <iostream>
#include <algorithm>

using namespace std;

//わからん

int main() {
    string s;
    cin >> s;
    int dp[100010][5] = {{0}}, i = 1;
    dp[0][0] = 0;
    for (auto c:s) {
        switch (c) {
            case 'y':
                dp[i][1] = min({dp[i-1][0], dp[i-1][4] + 1, dp[i-1][3] + 2, dp[i-1][2] + 2, dp[i-1][1] + 1});
                break;
            case 'a':
                if (i <= 1) i += 5;
                if (i + aida >= 6) cnt += aida;
                else cnt += 6 - i;
                aida = 0;
                i = 2;
                break;
            case 'h':
                if (i <= 2) i += 5;
                if (i + aida >= 7) cnt += aida;
                else cnt += 7 - i;
                aida = 0;
                i = 3;
                break;
            case 'o':
                if (i + aida >= 6) cnt += aida;
                else cnt += 6 - i;
                aida = 0;
                i = 2;
                break;
            default:
                aida++;
        }
    }
    cout << cnt << '\n';
    return 0;
}