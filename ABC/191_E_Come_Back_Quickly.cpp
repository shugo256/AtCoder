#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

#include <limits>

using namespace std;

// 各点への最短経路 dijkstra
template<typename dist_t>
class Dijkstra {
    using elem_t = pair<dist_t, int>;

    int n, // 頂点数
        input_edge_num; // 辺の数
    std::vector<elem_t> *G;

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
const dist_t Dijkstra<dist_t>::INF = dist_t(1e13);

/* Constructers
 *
 * Dijkstra(int _n) 
 * Dijkstra(int _n, vector<elem_t>* &_G)
 */

int main() {
    int n, m;
    std::cin >> n >> m;
    Dijkstra<ll> jyun(n), gyak(n);
    std::vector<ll> self(n, Dijkstra<ll>::INF);

    for (int i=0, ai, bi; i<m; i++){
        ll ci;
        std::cin >> ai >> bi >> ci;
        ai--; bi--;
        if (ai == bi) {
            amin(self[ai], ci);
        } else {
            jyun.add_edge(ai, bi, ci);
            gyak.add_edge(bi, ai, ci);
        }
    }
    
    for (int i=0; i<n; i++) {
        ll ans = self[i];

        auto jyunRes = jyun(i);
        auto gyakRes = gyak(i);

        for (int j=0; j<n; j++) {
            if (j == i) continue;
            amin(ans, jyunRes[j] + gyakRes[j]);
        }
        std::cout << (ans < Dijkstra<ll>::INF ? ans : -1) << '\n';
    }
    return 0;
}