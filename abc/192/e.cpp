#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;


struct edge {
    int to;
    ll cost, sche;
};

#define INF ll(1e16)

using P = std::pair<ll, int>;
#define fi first
#define se second

int main() {
    int n, m, start, goal;
    std::cin >> n >> m >> start >> goal;
    start--; goal--;
    std::vector<edge> G[n];
    for (int i=0; i<m; i++) {
        int ai, bi; ll ti, ki;
        std::cin >> ai >> bi >> ti >> ki;
        ai--; bi--;
        G[ai].push_back({bi, ti, ki});
        G[bi].push_back({ai, ti, ki});
    }
    std::vector<ll> dist(n, INF);
    dist[start] = 0;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        P p = pq.top(); pq.pop();
        int now = p.se;
        if (dist[now] < p.fi) continue;

        for (auto &g:G[now]) {
            int to = g.to;
            ll newd = g.cost + (dist[now] + g.sche - 1) / g.sche * g.sche;

            if (dist[to] > newd) {
                dist[to] = newd;
                pq.push(P(dist[to], to));
            }
        }
    }

    std::cout << (dist[goal] < INF ? dist[goal] : -1) << '\n';
    return 0;
}