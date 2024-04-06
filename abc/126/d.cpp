#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_N 100010

using namespace std;

typedef pair<int, bool> P;

int main() {
    int n;
    cin >> n;
    bool color[n], visited[MAX_N] = {0};
    vector<P> G[MAX_N];
    for (int i=0; i<n-1; i++) {
        int u, v;
        long w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({v, (bool)(w % 2)});
        G[v].push_back({u, (bool)(w % 2)});
    }
    queue<int> q;
    q.push(0); color[0] = false;
    while (!q.empty()) {
        int i = q.front(); q.pop();
        visited[i] = true;
        for (auto p:G[i]) {
            if (visited[p.first]) continue;
            q.push(p.first);
            color[p.first] = (p.second ? !color[i] : color[i]);
            //cerr << i << ' ' << p.first << ' ' << color[p.first] << '\n';
        }
    }
    for (auto c:color)
        cout << (int)c << '\n';
    return 0;
}
