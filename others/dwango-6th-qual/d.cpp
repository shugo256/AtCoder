#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1 << '\n';
        return 0;
    }
    int a[n+1]; 
    map<int, set<int>> cnt;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i]--;
        cnt[a[i]].insert(i);
    }
    a[n] = -1;
    for (auto itr = cnt.begin(); itr != cnt.end(); (itr->second.size() ? ++itr : itr = cnt.erase(itr)));
    set<int> s;
    for (int i=0; i<n; i++) s.insert(i);
    int prev = n;
    vector<int> ans;
    for (int i=0; i<n-3; i++) {
        auto citr0 = cnt.begin();
        auto citr1 = ++cnt.begin();
        if (cnt.size() == 2 && citr0->second.size() == 1 && s.count(citr1->first)) {
            prev = citr1->first;
        } else if (cnt.size() == 2 && citr1->second.size() == 1 && s.count(citr0->first)) {
            prev = citr0->first;
        } else {
            auto itr = s.begin();
            if (*itr == a[prev]) itr++;
            prev = *itr;
        }
        ans.push_back(prev);
        s.erase(prev);
        cnt[a[prev]].erase(prev);
        if (cnt[a[prev]].size() == 0) cnt.erase(a[prev]);
    }
    for (auto &si:s) ans.push_back(si);
    do {
        bool success = true;
        int p = prev;
        for (int i=n-3; i<n; i++) {
            if (ans[i] == a[p]) {
                success = false;
                break;
            }
            p = ans[i];
        }
        if (success) break;
    } while (next_permutation(ans.begin() + n-3, ans.end()));
    for (auto &ai:ans) cout << ai + 1 << ' ';
    cout << '\n';
    return 0;
}