#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <functional>

using ll = long long;

using namespace std;

struct section{long l, r;};

using pq = priority_queue<int, vector<int>, function<bool(int, int)>> ;

section s[100010];
int n;

long journey(bool di, pq ql, pq qr) {
    long res = 0, prev = 0;
    for (int i=0; i<n; i++) {
        if (di && !ql.empty()) {
            int j = ql.top(); ql.pop();
            if (s[j].l > prev) {
                res += s[j].l - prev;
                prev = s[j].l;
                di = !di;
            } else 
                break;
        } else if (!qr.empty()) {
            int j = qr.top(); qr.pop();
            if (s[j].r < prev) {
                res -= s[j].r - prev;
                prev = s[j].r;
                di = !di;
            } else 
                break;
        }
    }
    return res + abs(prev);
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> s[i].l >> s[i].r;
    pq ql(
        [&](int a, int b) {
            return s[a].l < s[b].l;
        }
    );
    pq qr(
        [&](int a, int b) {
            return s[a].r > s[b].r;
        }
    );
    for (int i=0; i<n; i++) (ql.push(i), qr.push(i));
    cout << max(journey(true, ql, qr), journey(false, ql, qr)) << '\n';
    return 0;
}