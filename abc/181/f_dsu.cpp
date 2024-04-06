#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <cmath>
#include <atcoder/dsu>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ld = long double;

struct edge {
    int u, v;
    ld dist;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<ld, ld>> points(n);
    for (auto &[xi, yi] : points) {
        std::cin >> xi >> yi;
    }

    std::vector<edge> edges(1, {0, n+1, 200});

    for (int i = 0; i < n; i++) {
        auto [xi, yi] = points[i];
        edges.push_back({i+1, 0, 100 - yi});
        edges.push_back({i+1, n+1, yi - (-100)});
        for (int j = 0; j < i; j++) {
            auto [xj, yj] = points[j];
            edges.push_back({i+1, j+1, std::hypotl(xi - xj, yi - yj)});
        }
    }

    std::sort(edges.begin(), edges.end(), [](const edge &l, const edge &r) {
        return l.dist < r.dist;
    });

    atcoder::dsu dsu(n + 2);
    
    for (auto &[u, v, d] : edges) {
        dsu.merge(u, v);
        if (dsu.same(0, n+1)) {
            std::cout << std::setprecision(15) << std::fixed << d / 2 << '\n';
            break;
        }
    }
    return 0;
}