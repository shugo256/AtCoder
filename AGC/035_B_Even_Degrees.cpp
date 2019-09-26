#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using namespace std;

using ll = long long;

int par[100010], child[100010] = {0};
set<int> G[100010];
queue<int> q, bottoms;

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
    fill(par, par+n, -1);
    par[0] = 0;
    q.push(0);
    bool visited[100010] = {0};
    while (!q.empty()) {
        int f = q.front(); q.pop();
        for (auto g:G[f]) {
            if (visited[g]) continue;
            visited[g] = true;
            child[f]++;
            par[g] = f;
            q.push(g);
        }
    }
    set<int> ans[n];
    for (int i=0; i<n; i++)
        if (child[i] == 0)
            bottoms.push(i);
    while (!bottoms.empty()) {
        int b = bottoms.front(); bottoms.pop();
        for (auto g:G[b]) {
            if (g == par[b] && G[b].size() % 2) {
                ans[g].insert(b);
            } else if (ans[g].find(b) != ans[g].end()) {
                ans[b].insert(g);
                G[g].erase(b);
            }
        }
        child[par[b]]--;
        if (b > 0 && child[par[b]] == 0) bottoms.push(par[b]);
    }
    for (int i=0; i<n; i++)
        for (auto g:ans[i])
            cout << i+1 << ' ' << g+1 << '\n';
    return 0;
}