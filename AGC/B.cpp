#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

int main() {
    string s; cin >> s;
    int now = 0, high = 0, low = 0;
    queue<P> q;
    P p = {0, 0};
    for (auto &c:s) {
        if (c == '0') {
            p.se--;
        }
        else if (c == '1' ) {
            p.fi++;
        } else if (p != P{0, 0}) {
            q.push(p);
            p = {0, 0};
        }
    }
    q.push({0, 0});
    bool hatena = true;
    for (auto &c:s) {
        if (c == '?') {
            hatena = true;
            if (now + q.front().fi > high) {
                now--;
            } else if (now + q.front().fi < high) {
                now++;
            } else {
                if (now + q.front().se > low) {
                    now--;
                } else {
                    now++;
                }
            }
        } else if (hatena) {
            hatena = false;
            q.pop();
        }
        if (c == '1') {
            now++;
        } else if (c == '0') {
            now--;
        }
        high = max(high, now);
        low = min(low, now);
        cerr << now << ' ' << low << ' ' << high << ' ' << c << '\n';
    }
    cout << high - low << '\n';
    return 0;
}