#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    string t;
    cin >> t;
    ll ans = 0, cnt = 0;
    bool one = true;
    for (auto &c:t) {
        if (c == '1' || !one) {
            if (one) 
                cnt++;
            if (c == '0') 
                c = '-';
            ans += cnt;
            one ^= 1;
        }
    }
    reverse(t.begin(), t.end());
    one ^= 1;
    ll sum = 0, odds = 0;
    for (auto &c:t) {
        if (c == '0') {
            cnt -= odds;
            odds = sum - odds;
            cnt += odds;
            ans += cnt;
        } else {
            if (c == '1') {
                if (one) odds++;
                sum++;
            }
            one ^= 1;
        }
    }
    cout << ans << '\n';
    return 0;
}