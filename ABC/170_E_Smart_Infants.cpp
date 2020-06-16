#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

int main() {
    int n, q;
    cin >> n >> q;
    P infants[n];
    multiset<int> kinders[200010];
    for (auto &ki:kinders) ki.insert(0);
    for (auto &ii: infants) {
        cin >> ii.fi >> ii.se;
        ii.se--;
        kinders[ii.se].insert(ii.fi);
    }
    multiset<int> master;
    for (auto &ki:kinders) {
        master.insert(*prev(ki.end()));
    }
    for (int i=0, ci, di; i<q; i++) {
        cin >> ci >> di;
        ci--; di--;
        int before = infants[ci].se;
        int after  = di;
        infants[ci].se = di;
        // 退園
        master.erase(master.find(*prev(kinders[before].end())));
        kinders[before].erase(infants[ci].fi);
        master.insert(*prev(kinders[before].end()));
        // 入園
        master.erase(master.find(*prev(kinders[after].end())));
        kinders[after].insert(infants[ci].fi);
        master.insert(*prev(kinders[after].end()));

        cout << *master.upper_bound(0) << '\n';
    }
    return 0;
}