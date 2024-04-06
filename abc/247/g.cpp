#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/mincostflow>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

constexpr int MAX_GROUP = 150;
constexpr ll OFFSET = 1e10;

int main() {
    int n;
    std::cin >> n;
    const int start = MAX_GROUP * 2;
    const int end   = MAX_GROUP * 2 + 1;
    atcoder::mcf_graph<int, ll> graph((MAX_GROUP + 1) * 2);
    for (int i = 0; i < MAX_GROUP; i++) {
        graph.add_edge(start, i, 1, 0);
        graph.add_edge(i + MAX_GROUP, end, 1, 0);
    }
    for (int i = 0, ai, bi, ci; i < n; i++) {
        std::cin >> ai >> bi >> ci;
        ai--; bi--;
        graph.add_edge(ai, bi + MAX_GROUP, 1, OFFSET - ci);
    }

    int prevF = -1;
    ll prevC = -1;
    std::vector<ll> ans;
    for (auto &[f, c] : graph.slope(start, end)) {
        if (prevF >= 0) {
            ll step = (c - prevC) / (f - prevF);
            ll cost = prevC;
            // std::cerr << f << ' ' << c << ' ' << step << ' ' << prevF << ' ' << prevC << std::endl;
            for (int i = prevF; i < f; i++) {
                cost += step;
                // std::cerr << cost << std::endl;
                ans.push_back(OFFSET * (i+1) - cost);
            }
        }
        prevF = f; prevC = c;
    }

    std::cout << ans.size() << '\n';
    for (auto &ai : ans) {
        std::cout << ai << '\n';
    }
    return 0;
}