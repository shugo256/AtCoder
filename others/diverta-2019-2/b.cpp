/*
 * 復習
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

P dif(P a, P b) {
    P ab = {a.fi - b.fi, a.se - b.se};
    P ba = {b.fi - a.fi, b.se - a.se};
    return max(ab, ba);
}

int main() {
    int n;
    cin >> n;
    P balls[n];
    for (auto &bi:balls) {
        cin >> bi.fi >> bi.se;
    }
    int ans = 0;
    map<P, int> cnt;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            P d = dif(balls[i], balls[j]);
            cnt[d]++;
            ans = max(ans, cnt[d]);
        }
    }
    cout << n - ans << '\n';
    return 0;
}