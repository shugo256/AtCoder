#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

#define INF (long)1e15
#define MAX_N (int)(1e5+1)

using namespace std;

typedef pair<long, int> P;

int N;
long d[MAX_N] = {0};

void dijkstra(vector<P> G[]) {
    long d1[MAX_N];
    fill(d1, d1+N, INF); d1[0] = 0;
    priority_queue< P, vector<P>, greater<P> > que;
    que.push(P(0, 0));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int n = p.second;
        if (d1[n] < p.first) continue;
        for (size_t i=0; i<G[n].size(); i++) {
            int to = G[n][i].second;
            long newd = G[n][i].first + d1[n];
            if (d1[to] > newd) {
                d1[to] = newd;
                que.push(P(d1[to], to));
            }
        }
    }
    for (int i=0; i<N; i++) d[i] += d1[i];
    return;
}

int main() {
    int M;
    long T;
    scanf("%d %d %ld", &N, &M, &T);
    long A[N];
    for (int i=0; i<N; i++) scanf("%ld", A+i);
    vector<P> G[N], I[N]; // IはGのすべての辺を逆向きにしたver
    for (int i=0; i<M; i++) {
        int a, b;
        long c;
        scanf("%d %d %ld", &a, &b, &c);
        G[a-1].push_back(P(c, b-1));
        I[b-1].push_back(P(c, a-1));
    }
    dijkstra(G); //行き
    dijkstra(I); //帰り
    long treasure=0;
    for (int i=0; i<N; i++) treasure = max(treasure, (T > d[i]) ? A[i] * (T - d[i]) : 0);
    printf("%ld\n", treasure);
    return 0;
}