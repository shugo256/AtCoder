#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

struct edge{int u, v, w;};

int main() {
    int l;
    cin >> l;
    int d = 1 << 20, i = 1;
    for ( ; (2 * d & l) == 0; d >>= 1);
    vector<edge> ans;
    for (int cur=2 * d; d > 0; (i++, d >>= 1)) {
        ans.push_back(edge{i, i+1, 0});
        ans.push_back(edge{i, i+1, d});
        if (l - cur >= d) {
            ans.push_back(edge{1, i+1, cur});
            cur += d;
        }
    }
    cout << i << ' ' << ans.size() << '\n';
    for (auto &e:ans) cout << e.u << ' ' << e.v << ' ' << e.w << '\n';
    return 0;
}