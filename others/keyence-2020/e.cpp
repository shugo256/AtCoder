#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <functional>
#include <set>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

vector<P> G[100010]; // fiが行先、seがへんの番号
int d[100010],     // 入力
    edge[200010]; // 各辺の長さ

bool visited[100010] = {0},
     color[100010] = {0};

int main() {
    int n, m;
    cin >> n >> m;
    int mi = (int)1e9;
    for (int i=0; i<n; i++) {
        cin >> d[i];
        mi = min(mi, d[i]);
    }
    int root = -1;
    for (int i=0, ui, vi; i<m; i++) {
        cin >> ui >> vi;
        ui--; vi--;
        if (d[ui] == mi && d[vi] == mi) root = ui;
        G[ui].push_back({vi, i});
        G[vi].push_back({ui, i});
    }
    if (root < 0) {
        cout << -1 << '\n';
        return 0;
    }
    set<int, function<bool(int, int) >> s([&](int l, int r) {
        return d[l] < d[r];
    });
    s.insert(root);
    visited[root] = true;
    fill(edge, edge+m, (int)1e9);
    while (!s.empty()) {
        int i = *s.begin();
        s.erase(i);
        for (auto &g:G[i]) {
            if (visited[g.fi]) continue;
            visited[g.fi] = true;
            
        }
    }
    for (int i=0; i<n; i++) {
        cout << (color[i] ? 'B' : 'W');
    }
    cout << '\n';
    for (int i=0; i<m; i++) {
        cout << edge[i] << '\n';
    }
    return 0;
}