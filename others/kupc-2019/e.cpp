#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

vector<int> G[200010];
int p[200010];
int dfs(int i) {
    set<int> app;
    for (auto &g:G[i]) {
        if (g == p[i]) continue;
        app.insert(dfs(g));
    }
    int ans=0;
    for (auto &a:app) {
        if (ans != a) break;
        else ans++;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int ans = 0, cur = 0;
    for (int i=0, m; i<n; i++) {
        cin >> m;
        p[cur] = cur;
        for (int j=cur+1; j<cur+m; j++) {
            cin >> p[j];
            p[j] += cur - 1;
            //cerr << p[j] << ' ' << j << ' ' << cur << '\n';
            G[p[j]].push_back(j);
        }
        ans ^= (dfs(cur) > 0 ? 0 : 1);
        cur += m;
    }
    //cerr << ans << '\n';
    cout << (ans ? "Alice" : "Bob") << '\n';
    return 0;
}