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
    s += '$';
    long l = 0, r = 0, ans = 0;
    bool left = true;
    char prev = '<';
    for (auto &c:s) {
        if (c == prev) {
            if (left) l++;
            else r++;
        } else {
            if (left) {
                r++;
                ans += l * (l+1) / 2;
            } else {
                long amari = min(l, r);
                ans += r * (r+1) / 2;
                ans -= amari;
                l = 1;
                r = 0;
            }
            left = !left;
        }
        prev = c;
        //cerr << c << ' ' << l << ' ' << r << ' ' << ans << '\n';
    }
    cout << ans << '\n';
    return 0;
}