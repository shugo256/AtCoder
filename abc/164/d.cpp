#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    string s;
    cin >> s;
    ll cnt[2019] = {0}, ans = 0;
    int r = 0, d = 1;
    cnt[0] = 1;
    reverse(s.begin(), s.end());
    for (auto &c:s) {
        r = (r + (c - '0') * d) % 2019;
        d = d * 10 % 2019;
        ans += cnt[r];
        cnt[r]++;
    }
    cout << ans << '\n';
    return 0;
}