#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using namespace std;

using ll = long long;

using P = pair<int, int>;
#define fi first
#define se second

set<int> G[100010];

int main() {
    int n, m;
    cin >> n >> m;
    if (m % 2) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i=0, a, b; i<m; i++) {
        cin >> a >> b;
        a--; b--;
        G[a].insert(b);
        G[b].insert(a);
    }
    set<P> s;
    for (int i=0; i<n; i++) s.insert(P{G[i].size(), i});
    vector<P> ans;
    vector<int> erlist;
    int deg[n];
    fill(deg, deg+n, 0);
    for (int j; !s.empty(); ) {
        j = s.begin()->se;
        s.erase(s.begin());
        erlist.clear();
        for (auto &g:G[j]) {
            if ((deg[j] & 1) == 0) {
                ans.push_back(P{g+1, j+1});
                deg[g]++;
            } else {
                ans.push_back(P{j+1, g+1});
                deg[j]++;
            }
            erlist.push_back(g);
        }
        for (auto &e:erlist) {
            s.erase(P{G[e].size(), e});
            G[e].erase(j);
            s.insert(P{G[e].size(), e});
        }
        //cerr << j << ' ' << G[j].size() << '\n';
    }
    for (auto &ai:ans) cout << ai.fi << ' ' << ai.se << '\n';
    return 0;
}