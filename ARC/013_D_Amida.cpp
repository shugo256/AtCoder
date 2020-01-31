#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <numeric>

using ll = long long;

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    int s[n];
    iota(s, s+n, 0);
    for (int i=0, a; i<m; i++) {
        cin >> a;
        swap(s[a-1], s[a]);
    }
    bool used[n];
    fill(used, used+n, false);
    vector<int> loop[n];
    for (int i=0; i<n; i++) {
        if (used[i]) continue;
        used[i] = true;
        int p = s[i];
        loop[i].push_back(i);
        while (p != i) {
            used[p] = true;
            loop[i].push_back(p);
            p = s[p];
        }
    }
    int ans[n];
    for (int i=0; i<n; i++) {
        if (loop[i].empty()) continue;
        int l = loop[i].size(),
            r = d % l - l;
        for (int j=0; j<l; j++)
            ans[loop[i][j]] = loop[i][(j - r) % l];
    }
    for (auto &ai:ans) cout << ai + 1 << '\n';
    return 0;
}