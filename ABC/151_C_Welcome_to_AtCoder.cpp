#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

using P = pair<bool, int>;
#define fi first
#define se second

int main() {
    int n, m;
    cin >> n >> m;
    P res[n];
    fill(res, res+n, P{false, 0});
    for (int i=0, p; i<m; i++) {
        string s;
        cin >> p >> s;
        p--;
        if (res[p].fi) continue;
        if (s == "AC") res[p].fi = true;
        else res[p].se++;
    }
    int ac = 0, wa = 0;
    for (auto &r:res) {
        if (!r.fi) continue;
        ac++;
        wa += r.se;
    }
    cout << ac << ' ' << wa << '\n';
    return 0;
}