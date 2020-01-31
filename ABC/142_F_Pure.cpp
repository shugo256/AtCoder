#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int n, m;
vector<int> G[1010], ans, trace;
int from[1010];

void bfs(int i) {
    queue<int> q;
    fill(from, from+n, -1);
    q.push(i);
    while (!q.empty()) {
        int f = q.front(); q.pop();
        for (auto g:G[f]) {
            if (g == i) {
                trace = vector<int>();
                trace.push_back(i + 1);
                while (f != i) {
                    trace.push_back(f + 1);
                    f = from[f];
                }
                if (ans.size() == 0 || ans.size() > trace.size()) swap(ans, trace);
                return;
            }
            if (from[g] >= 0) continue;
            q.push(g);
            from[g] = f;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i=0, a, b; i<m; i++) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
    }
    for (int i=0; i<n; i++) bfs(i);
    if (ans.size() == 0)
        cout << -1 << '\n';
    else {
        cout << ans.size() << '\n';
        for (auto ai:ans) cout << ai << '\n';
    }
    return 0;
}
