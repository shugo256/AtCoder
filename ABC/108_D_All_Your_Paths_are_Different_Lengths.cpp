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
    int d = (1 << 18), cur = 0;
    vector<edge> ans;
    for (int i=2; i<20; (i++, d >>= 1)) {
        ans.push_back(edge{i, i+1, 0});
        ans.push_back(edge{i, i+1, d});
        if (l - cur >= d) {
            ans.push_back(edge{1, i, d});
            cur += d;
        }
    }
    cout << "20 " << ans.size() << '\n';
    for (auto &e:ans) cout << e.u << ' ' << e.v << ' ' << e.w << '\n';
    return 0;
}