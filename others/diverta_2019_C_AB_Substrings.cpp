#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n, cnt=0, acnt=0, bcnt=0, both=0;
    cin >> n;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        bool a=false;
        bool topb = (s[0] == 'B');
        for (auto c:s) {
            if (a && c == 'B') cnt++;
            if (c == 'A') a = true;
            else a = false;
        }
        if (a && topb) both++;
        else if (a) acnt++;
        else if (topb) bcnt++;
    }
    //cerr << acnt << bcnt << both << cnt << '\n';
    int ans;
    if (acnt > 0 && bcnt > 0) ans = min(acnt, bcnt) + both + cnt;
    else if (acnt == 0 && bcnt == 0) ans = max(both - 1, 0) + cnt;
    else ans = both + cnt;
    cout << ans << '\n';
    return 0;
}
