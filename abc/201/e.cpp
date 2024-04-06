#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/modint>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

using modint = atcoder::modint1000000007;

struct edge {
    int to;
    ll weight;
};

void dfs(std::vector<std::vector<edge>> &G, std::vector<ll> &xors, int i = 0, int par = -1) {
    for (auto &[t, w] : G[i]) {
        if (t == par) continue;
        xors[t] = xors[i] ^ w;
        dfs(G, xors, t, i);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector G(n, std::vector<edge>());
    for (int i = 0, ui, vi; i < n-1; i++) {
        ll wi;
        std::cin >> ui >> vi >> wi;
        ui--; vi--;
        G[ui].push_back({vi, wi});
        G[vi].push_back({ui, wi});
    }

    std::vector<ll> xors(n, 0);
    dfs(G, xors);

    std::vector<int> bitCounts(60, 0);
    for (auto &xi : xors) {
        for (int i = 0; i < 60; i++) {
            if ((xi >> i) & 1) {
                bitCounts[i]++;
            }
        }
    }

    modint ans = 0;
    for (int i = 0; i < 60; i++) {
        // std::cerr << i << ' ' << bitCounts[i] << ' ' << modint(2).pow(i).val() << std::endl;
        ans += modint(2).pow(i) * bitCounts[i] * (n - bitCounts[i]);
    }

    std::cout << ans.val() << '\n';
    return 0;
}