#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_N 100000
#define INF 1000000

using namespace std;

typedef pair<int, int> P;

long d[2][MAX_N];
int N; 
void dijkstra(vector<P> G[], int k, int i) { //Gは隣接行列 G[i][j].firstが距離, secondが向かう頂点名, kはスタートする頂点
    fill(d[i], d[i]+N, INF); d[i][k] = 0;
    priority_queue< P, vector<P>, greater<P> > que;
    que.push(P(0, k));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int now = p.second;
        if (d[i][now] < p.first) continue;
        for (size_t j=0; j<G[now].size(); j++) {
            int to = G[now][j].second; long newd = G[now][j].first + d[i][now];
            if (d[i][to] > newd) {
                d[i][to] = newd;
                que.push(P(d[i][to], to));
            }
        }
    }
}

int main() {
    cin >> N;
    vector<P> G[N];
    for (int i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back({1, b});
        G[b].push_back({1, a});
    }
    dijkstra(G, 0, 0);
    dijkstra(G, N-1, 1);
    int fencnt=0;
    for (int i=0; i<N; i++)
        if (d[0][i] <= d[1][i]) 
            fencnt++;
    // cerr << "DEBUG" << '\n';
    // for (int i=0; i<N; i++) cerr << d[0][i] << ' ' << d[1][i] << '\n';
    // cerr << fencnt << '\n';
    cout << (fencnt > N - fencnt ? "Fennec" : "Snuke") << '\n';
    return 0;
}