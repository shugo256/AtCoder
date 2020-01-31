#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>

#define INF 10000000
#define MAX_N 3000000

using namespace std;
using P = pair<int, int>;


long d[MAX_N];       //頂点kから各点への距離
vector<P> G[MAX_N];  //隣接行列
int n, m;
void dijkstra(int k) { 
    fill(d, d + MAX_N, INF);
    d[k] = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0, k));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int now = p.second;
        if (d[now] < p.first) continue;
        for (auto g : G[now]) {
            int to = g.second;
            long newd = g.first + d[now];
            if (d[to] > newd) {
                d[to] = newd;
                que.push(P(d[to], to));
            }
        }
    }
}

long key(P p) { return (long) p.first * (long)1e9 + p.second; }

int main() {
    cin >> n >> m;
    unordered_map<long, int> um;
    for (int i=1; i<=n; i++) um[key({i, -1})] = i;
    int msize = n;
    for (int i=0; i<m; i++) {
        int p, q, c;
        cin >> p >> q >> c;
        long pk = key({p, c}), qk = key({q, c});
        if (um[pk] == 0) {
            msize++;
            um[pk] = msize;
            G[p].push_back({1, um[pk]});
            G[um[pk]].push_back({0, p});
        }
        if (um[qk] == 0) {
            msize++;
            um[qk] = msize;
            G[q].push_back({1, um[qk]});
            G[um[qk]].push_back({0, q});
        }
        G[um[pk]].push_back({0, um[qk]});
        G[um[qk]].push_back({0, um[pk]});
    }
    dijkstra(1);
    cout << (d[n] < INF ? d[n] : -1) << '\n';
    return 0;
}