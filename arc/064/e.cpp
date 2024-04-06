#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>

using ll = long long;

using namespace std;

struct barrier { ll x, y, r=0; };

#define MAX_N 2000
#define INF (1e18)

using P = pair<double, int>;
#define fi first
#define se second

// 各点への最短経路 dijkstra
double d[MAX_N];  //頂点kから各点への距離
vector<P> G[MAX_N]; //隣接行列
int n; 
void dijkstra(int k) { //Gは隣接行列 G[i][j].firstが距離, secondが向かう頂点名, kはスタートする頂点
    fill(d, d+n, INF); d[k] = 0;
    priority_queue< P, vector<P>, greater<P> > que;
    que.push(P(0, k));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int now = p.second;
        if (d[now] < p.first) continue;
        for (auto g:G[now]) {
            int to = g.second;
            double newd = g.first + d[now];
            if (d[to] > newd) {
                d[to] = newd;
                que.push(P(d[to], to));
            }
        }
    }
}

int main() {
    barrier s, t;
    cin >> s.x >> s.y >> t.x >> t.y >> n;
    barrier bars[n+2];
    bars[0] = s;
    bars[1] = t;
    for (int i=0; i<n; i++) cin >> bars[i+2].x >> bars[i+2].y >> bars[i+2].r;
    n += 2;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            double dij = max(0., hypot(bars[i].x - bars[j].x, bars[i].y - bars[j].y) - bars[i].r - bars[j].r);
            G[i].push_back({dij, j});
            G[j].push_back({dij, i});
        }
    }
    dijkstra(0);
    cout << setprecision(15) << fixed << d[1] << '\n';
    return 0;
}