#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define INF (long)1e15

using namespace std;

typedef pair<long, int> P;

int main() {
    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    s--; t--;
    vector<P> Y[n], S[n]; // 円、スヌーくそれぞれの交通費
    for (int i=0; i<m; i++) {
        int u, v; long a, b;
        scanf("%d %d %ld %ld", &u, &v, &a, &b);
        u--; v--;
        Y[u].push_back(P(a, v));
        Y[v].push_back(P(a, u));
        S[u].push_back(P(b, v));
        S[v].push_back(P(b, u));
    }
    long dy[n], ds[n];
    priority_queue<P, vector<P>, greater<P>> que;
    fill(dy, dy+n, INF);
    dy[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int now = p.second;
        if (dy[now] < p.first) continue;
        for (size_t j=0; j<Y[now].size(); j++) {
            int to = Y[now][j].second; long newd = Y[now][j].first + dy[now];
            if (dy[to] > newd) {
                dy[to] = newd;
                que.push(P(dy[to], to));
            }
        }
    }
    fill(ds, ds+n, INF);
    ds[t] = 0;
    que.push(P(0, t));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int now = p.second;
        if (ds[now] < p.first) continue;
        for (size_t j=0; j<S[now].size(); j++) {
            int to = S[now][j].second; long newd = S[now][j].first + ds[now];
            if (ds[to] > newd) {
                ds[to] = newd;
                que.push(P(ds[to], to));
            }
        }
    }
    for (int i=0; i<n; i++) que.push(P(dy[i]+ds[i], i));
    P min = que.top(); que.pop();
    for (int i=0; i<n; i++) {
        while(min.second < i) {
            min = que.top(); que.pop();
        }
        printf("%ld\n", INF - min.first);
    }
    return 0;
}