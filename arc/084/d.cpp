#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>

#define INF 100

using namespace std;
typedef pair<int, int> P;

int main() {
    int K;
    scanf("%d", &K);
    vector<P> G[K]; // modKのグラフ 1たすか10倍するかの遷移
    for (int i=0; i<K; i++) {
        G[i].push_back(P(1, (i+1)%K));
        G[i].push_back(P(0, (i*10)%K));
    }
    int d[K];
    fill(d, d+K, INF); d[1] = 1;
    priority_queue< P, vector<P>, greater<P> > que;
    que.push(P(0, 1));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int now = p.second;
        if (d[now] < p.first) continue;
        for (size_t j=0; j<G[now].size(); j++) {
            int to = G[now][j].second; int newd = G[now][j].first + d[now];
            if (d[to] > newd) {
                d[to] = newd;
                que.push(P(d[to], to));
            }
        }
    }
    printf("%d\n", d[0]);
    return 0;
}