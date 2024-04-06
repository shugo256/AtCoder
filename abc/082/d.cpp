#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main() {
    bool dp[2][16001] = {{0}};
    dp[0][8000] = dp[1][8000] = true;
    int fcnt=0, tcnt=0;
    string s; cin >> s;
    s += 'T';
    for (auto c:s) {
        if (c == 'F') fcnt++;
        else {
            bool buf[16001] = {0};
            for (int i=0; i<=16000; i++) {
                if (dp[tcnt%2][i]) {
                    if (tcnt > 0) 
                        buf[i - fcnt] = true;
                    buf[i + fcnt] = true;
                }
            }
            memcpy(dp[tcnt % 2], buf, 16001);
            tcnt++;
            fcnt = 0;
        }
    }
    int x, y;
    cin >> x >> y;
    cout << (dp[0][8000+x] && dp[1][8000+y] ? "Yes" : "No") << '\n';
    return 0;
}