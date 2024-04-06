#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

using P = pair<int, int>;

#define MAX_N 400000
#define INF 400000

// 各点への最短経路 dijkstra
long d[MAX_N];  //頂点kから各点への距離
vector<P> G[MAX_N]; //隣接行列
int n, m; 
void dijkstra(int k) { //Gは隣接行列 G[i][j].firstが距離, secondが向かう頂点名, kはスタートする頂点
    fill(d, d+3*n+1, INF); d[k] = 0;
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

int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back({1, v+n});
        G[u+n].push_back({1, v+2*n});
        G[u+2*n].push_back({1, v});
    }
    int s, t;
    cin >> s >> t;
    dijkstra(s);
    cout << (d[t] < INF ? d[t]/3 : -1) << '\n';
    return 0;
}
