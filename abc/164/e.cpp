#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#include <limits>

// 各点への最短経路 dijkstra
template<typename dist_t>
class Dijkstra {
    using elem_t = pair<dist_t, int>;

    int n; // 頂点数
    vector<elem_t> *G;

public:

    static const dist_t INF;

    Dijkstra(int _n) : n(_n), G(new vector<elem_t>[(size_t)n]) {}

    Dijkstra(int _n, vector<elem_t>* &_G) : n(_n), G(_G) {}

    inline void add_edge(int from, int to, dist_t dist=1) {
        G[from].push_back(elem_t{dist, to});
    }

    struct result {
        result(int _n, int k) : n(_n), d(new dist_t[(size_t)_n]) {
            fill(d, d+n, INF); 
            d[k] = 0;
        }
        auto &operator[](int i) { return d[i]; } 
        auto begin() { return d; }
        auto end()   { return d + n; }
        operator dist_t*() { return d; } // dist_t* へのキャスト

        bool unreachable(int i) { return d[i] == INF; }  // 視点から到達不可能かどうか
    private:
        const int n;
        dist_t *d;
    };

    inline result operator()(int start) {
        result d(n, start);

        priority_queue< elem_t, vector<elem_t>, greater<elem_t> > que;
        que.push(elem_t{0, start});

        while (!que.empty()) {
            elem_t p = que.top(); que.pop();
            int now = p.second;
            if (d[now] < p.first) continue;

            for (auto &g:G[now]) {
                int to = g.second;
                dist_t newd = g.first + d[now];

                if (d[to] > newd) {
                    d[to] = newd;
                    que.push(elem_t(d[to], to));
                }
            }
        }
        return d;
    }

    auto &operator[](int i) { return G[i]; } 
    auto begin() { return G; }
    auto end()   { return G + n; }
};

template<typename dist_t>
const dist_t Dijkstra<dist_t>::INF = numeric_limits<dist_t>::max();

/* Constructers
 *
 * Dijkstra(int _n) 
 * Dijkstra(int _n, vector<elem_t>* &_G)
 */


#define INF (ll)(1e17)
#define MAX_S 5010

#define node(actual, bit, s) ((2 * actual + bit) * MAX_S + s)

int main() {
    int n, m;
    ll s;
    cin >> n >> m >> s;
    ll U[m], V[m], A[m], B[m];
    Dijkstra<ll> dij(2 * n * MAX_S);
    for (int i=0; i<m; i++) {
        cin >> U[i] >> V[i] >> A[i] >> B[i];
        U[i]--; V[i]--;
        for (int j=A[i]; j<MAX_S; j++) {
            dij.add_edge(node(U[i], 1, j), node(V[i], 0, j-A[i]), B[i]);
            dij.add_edge(node(V[i], 1, j), node(U[i], 0, j-A[i]), B[i]);
        }
    }
    ll C[n];
    ll D[n];
    for (int i=0; i<n; i++) {
        cin >> C[i] >> D[i];
        for (int ss=0; ss<MAX_S; ss++) {
            if (ss + C[i] < MAX_S)
                dij.add_edge(node(i, 1, ss), node(i, 1, ss+C[i]), D[i]);
            dij.add_edge(node(i, 0, ss), node(i, 1, ss), 0);
        }
    }
    auto res = dij(node(0, 0, min(MAX_S-1, (int)s)));
    for (int i=1; i<n; i++) {
        ll ans = INF;
        for (int j=0; j<MAX_S; j++) {
            ans = min({ans, res[node(i, 0, j)], res[node(i, 1, j)]});
        }
        cout << ans << '\n';
    }
    return 0;
}