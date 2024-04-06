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

    bool directed,           // 有向グラフかどうか
         edge_length_input,  // 入力で辺の長さが与えられるかどうか(ない場合全て1に)
         zero_indexed_input; // 入力で与えられる頂点が0-indexedかどうか
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

int calcNodeId(int x, int y, int n, bool reverse) {
    if (reverse) {
        return (n + x) * n + y;
    } else {
        return x * n + y;
    }
}

int main() {
    int n, ax, ay, bx, by;
    std::cin >> n >> ax >> ay >> bx >> by;
    ax--; ay--; bx--; by--;
    std::vector board(n, std::string());
    for (auto &row : board) {
        std::cin >> row;
    }

    Dijkstra<int> dijk(n * n * 2);
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            dijk.add_edge(calcNodeId(x, y, n, false), calcNodeId(x, y, n, true), 1);
            dijk.add_edge(calcNodeId(x, y, n, true), calcNodeId(x, y, n, false), 1);
        }
    }
    for (int d = -n; d < n; d++) {
        for (int x = std::max(0, -d); x + 1 < n && x + 1 + d < n; x++) {
            if (board[x][x+d] == '#' || board[x+1][x+1+d] == '#') continue;
            // std::cerr << x << ' ' << x+d << std::endl;
            dijk.add_edge(calcNodeId(x, x + d, n, false), calcNodeId(x + 1, x + 1 + d, n, false), 0);
            dijk.add_edge(calcNodeId(x + 1, x + 1 + d, n, false), calcNodeId(x, x + d, n, false), 0);
        }
    }
    // std::cerr << "hoge" << std::endl;
    for (int s = 0; s < 2*n; s++) {
        for (int x = std::max(0, s - n + 1); x + 1 < n && s - x - 1 >= 0; x++) {
            if (board[x][s-x] == '#' || board[x+1][s-x-1] == '#') continue;
            // std::cerr << x << ' ' << s-x << std::endl;
            dijk.add_edge(calcNodeId(x, s-x, n, true), calcNodeId(x + 1, s-x-1, n, true), 0);
            dijk.add_edge(calcNodeId(x + 1, s-x-1, n, true), calcNodeId(x, s-x, n, true), 0);
        }
    }
    auto result = dijk(calcNodeId(ax, ay, n, false));
    auto resultRev = dijk(calcNodeId(ax, ay, n, true));

    int dist = std::min({
        result[calcNodeId(bx, by, n, false)],
        result[calcNodeId(bx, by, n, true)],
        resultRev[calcNodeId(bx, by, n, false)],
        resultRev[calcNodeId(bx, by, n, true)],
    });
    std::cout << (dist == Dijkstra<int>::INF ? -1 : dist + 1) << '\n';
    return 0;
}