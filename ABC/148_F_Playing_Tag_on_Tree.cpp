#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;
#define MAX_N 100010

using P = pair<int, int>;
#define fi first
#define se second

int n, taka, aoki;
vector<P> G[100010];

// 各点への最短経路 dijkstra
int ad[MAX_N], td[MAX_N];  //頂点kから各点への距離
void dijkstra(int k, int *d) { //Gは隣接行列 G[i][j].firstが距離, secondが向かう頂点名, kはスタートする頂点
    fill(d, d+n, MAX_N); d[k] = 0;
    priority_queue< P, vector<P>, greater<P> > que;
    que.push(P(0, k));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int now = p.second;
        if (d[now] < p.first) continue;
        for (auto g:G[now]) {
            int to = g.second;
            long newd = g.first + d[now];
            if (d[to] > newd) {
                d[to] = newd;
                que.push(P(d[to], to));
            }
        }
    }
}

bool under[MAX_N] = {0}, visited[MAX_N] = {0};

void dfs(int tr, int i=aoki) {
    visited[i] = true;
    if (i == tr) under[i] = true;
    for (auto &g:G[i]) {
        if (visited[g.se]) continue;
        if (under[i]) under[g.se] = true;
        dfs(tr, g.se);
    }
}


int main() {
    cin >> n >> taka >> aoki;
    taka--; aoki--;
    for (int i=0, a, b; i<n-1; i++) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back({1, b});
        G[b].push_back({1, a});
    }
    dijkstra(aoki, ad);
    dijkstra(taka, td);
    int ans = 0, tr = -1;
    for (int i=0; i<n; i++) {
        if (td[i] + ad[i] == ad[taka] && ad[i] == (ad[taka] + 2) / 2) {
            tr = i;
            break;
        }
    }
    cerr << tr << '\n';
    dfs(tr);
    for (int i=0; i<n; i++) {
        cerr << i << ' ' << under[i] << ' ' << ad[i] << '\n';
        if (under[i]) ans = max(ans, ad[i]);
    }
    cout << ans - 1 << '\n';
    return 0;
}