#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

#define MAX_L 100010
#define MAX_N 262145

#define amax(a, b) a = max(a, b);

using P = pair<int, int>;
#define fi first
#define se second

int v[MAX_N], w[MAX_N];
vector<int> ans[256];

void dfs(int i, int n, vector<vector<int>> &dp) {
    ans[i].resize(MAX_L, 0);
    vector<int> &prev = dp.back();
    vector<int> &cur  = ans[i];
    for (int j=0; j<MAX_L; j++) {
        amax(cur[j], prev[j]);
        if (j + 1 < MAX_L)
            amax(cur[j+1], prev[j]);
        if (j + w[i] < MAX_L)
            amax(cur[j+w[i]], prev[j] + v[i]);
    }
    dp.push_back(cur);
    if (i * 2 <= n) dfs(i * 2, n, dp);
    if (i * 2 + 1 <= n) dfs(i * 2 + 1, n, dp);
    dp.pop_back();
}

int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> v[i] >> w[i];
    }
    vector dp(1, vector<int>(MAX_L, 0));
    dfs(1, min(n, 255), dp);
    int q; cin >> q;
    for (int i=0, vi, li; i<q; i++) {
        cin >> vi >> li;
        vector<int> check;
        while (vi >= 256) {
            check.push_back(vi);
            vi /= 2;
        }
        vector<P> search(1, {0, 0});
        for (auto &ci:check) {
            vector<P> buf;
            for (auto &si:search) {
                buf.push_back(si);
                buf.push_back({si.fi + v[ci], si.se + w[ci]});
            }
            search.swap(buf);
        }
        int best = 0;
        for (auto &si:search) {
            if (si.se <= li) {
                amax(best, si.fi + ans[vi][li - si.se]);
            }
        }
        cout << best << '\n';
    }
    return 0;
}