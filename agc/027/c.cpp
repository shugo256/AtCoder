#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <queue>

using ll = long long;

using namespace std;

set<int> G[2][200010];

int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    s = '-' + s;
    for (int i=0, a, b; i<m; i++) {
        cin >> a >> b;
        G[(s[a] == 'A')][b].insert(a);
        G[(s[b] == 'A')][a].insert(b);
    }
    int cnt=n;
    bool visited[n+1];
    fill(visited, visited+n+1, false);
    queue<int> q;
    for (int i=1; i<=n; i++)
        if (G[0][i].empty() || G[1][i].empty()) {
            q.push(i);
            cnt--;
            visited[i] = true;
        }

    while (!q.empty()) {
        int t = q.front(); q.pop();
        for (int i=0; i<2; i++) {
            for (auto g:G[i][t]) {
                if (visited[g]) continue;
                G[(s[t] == 'A')][g].erase(t);
                if (G[(s[t] == 'A')][g].empty()) {
                    q.push(g);
                    visited[g] = true;
                    cnt--;
                }
            }
        }
    }
    cout << (cnt > 0 ? "Yes" : "No") << '\n';
    return 0;
}