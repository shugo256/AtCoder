#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 100000000

using namespace std;

using P = pair<int,int>;

// 各点への最短経路 dijkstra
long d[10];  //頂点kから各点への距離
vector<P> G[10]; //隣接行列
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
            long newd = g.first + d[now];
            if (d[to] > newd) {
                d[to] = newd;
                que.push(P(d[to], to));
            }
        }
    }
}

int main() {
    n = 10;
    int h, w;
    cin >>  h >> w;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            int c; cin >> c;
            if (i == j) continue;
            G[j].push_back({c, i});
        }
    }
    dijkstra(1);
    int sum=0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            int a; cin >> a;
            if (a < 0) continue;
            sum += d[a];
        }
    }
    cout << sum << '\n';
    return 0;
}