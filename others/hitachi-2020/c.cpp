#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <utility>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

vector<int> G[200010];


int main() {
    int n;
    cin >> n;
    for (int i=0, a, b; i<n-1; i++) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int color[n];
    fill(color, color+n, -1);
    color[0] = 0;
    queue<int> q;
    q.push(0);
    int cnt = 0;
    while (!q.empty()) {
        int i = q.front(); q.pop();
        for (auto &g:G[i]) {
            if (color[g] >= 0) continue;
            color[g] = color[i] ^ 1;
            cnt += color[g];
            q.push(g);
        }
    }
    int ans[n];
    fill(ans, ans+n, -1);
    set<int> s; for (int i=1; i<=n; i++) s.insert(i);
    if (cnt <= n / 3 || n - cnt <= n / 3) {
        int val = 3;
        for (int i=0; i<n; i++) {
            if (color[i] ^ (cnt > n / 3)) {
                ans[i] = val;
                s.erase(val);
                val += 3;
            }
        }
    } else {
        int vals[3] = {1, 2, 3};
        for (int i=0; i<n; i++) {
            int idx = (vals[color[i]] >= 0 ? color[i] : 2);
            ans[i] = vals[idx];
            s.erase(vals[idx]);
            vals[idx] += 3;
            if (vals[idx] > n) vals[idx] = -1;
        }
    }
    auto itr = s.begin();
    for (int i=0; i<n; i++) {
        if (ans[i] < 0) {
            ans[i] = *(itr++);
        }
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}