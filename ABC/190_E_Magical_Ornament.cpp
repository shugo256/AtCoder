#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <numeric>
#include <bitset>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

using P = std::pair<int, int>;
#define fi first
#define se second

constexpr int INF = 100000000;

void calcDist(std::vector<int> &dist, int start, std::vector<std::vector<int>> &G) {
    std::fill(dist.begin(), dist.end(), INF);
    dist[start] = 0;

    std::queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int t = q.front(); q.pop();
        for (auto &g:G[t]) {
            if (dist[g] > dist[t] + 1) {
                dist[g] = dist[t] + 1;
                q.push(g);
            }
        }
    }
    // for (auto &di:dist) {
    //     std::cerr << di << ' ';
    // }
    // std::cerr << std::endl;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector G(n, std::vector<int>());
    for (int i=0, ai, bi; i<m; i++) {
        std::cin >> ai >> bi;
        ai--; bi--;
        G[ai].push_back(bi);
        G[bi].push_back(ai);
    }
    int k;
    std::cin >> k;
    std::vector<int> c(k);
    std::vector dist(k, std::vector<int>(n));
    for (int i=0; i<k; i++) {
        std::cin >> c[i];
        c[i]--;
        calcDist(dist[i], c[i], G);
    }

    std::vector dp((1 << k), std::vector(k, INF));
    for (int i=0; i<k; i++) {
        dp[(1 << i)][i] = 0;
    }
    
    std::vector<int> idxs((1 << k) - 1);
    std::iota(idxs.begin(), idxs.end(), 1);
    std::sort(idxs.begin(), idxs.end(), [&](int l, int r) {
        return std::bitset<17>(l).count() < std::bitset<17>(r).count();
    });
    
    for (auto &i:idxs) {
        for (int j=0; j<k; j++) {
            for (int l=0; l<k; l++) {
                if (i & (1 << l)) continue;
                amin(dp[i | (1 << l)][l], dp[i][j] + dist[j][c[l]]);
            }
        }
    }
    // for (auto &dpi:dp) {
    //     for (auto &dpij:dpi) {
    //         std::cerr << dpij << ' ';
    //     }
    //     std::cerr << std::endl;
    // }
    int ans = INF;
    for (auto &dpi:dp[(1 << k) - 1]) {
        amin(ans, dpi);
    }
    std::cout << (ans < INF ? ans + 1 : -1) << '\n';
    return 0;
}