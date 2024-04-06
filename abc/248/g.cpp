#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <numeric>
#include <unordered_map>
#include <atcoder/modint>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;
using modint = atcoder::modint998244353;

constexpr int MAX = int(1e5) + 1;

#include <set>
// vecのなかの全要素について座標圧縮を行い、元座標->圧縮後座標というmapを作る
// O(NlogN) 座圧後のサイズを返す
// org: もともとの各iに対する座標 値渡しなので破壊しません
// zip: 圧縮
// unzip: 復元
template <typename T>
int compress(std::vector<T> org, std::unordered_map<T, int> &zip, std::vector<T> &unzip) {
    int i = 0;
    for (auto &oi : org) {
        if (zip.count(oi) > 0) continue;
        zip[oi] = i;
        unzip.push_back(oi);
        i++;
    }
    return i;
}

std::vector<modint> calcCoefs() {
    std::vector<modint> coeffs(MAX, 0);
    for (int i = 1; i < MAX; i++) {
        coeffs[i] += i;
        for (int c = 2; i * c < MAX; c++) {
            coeffs[i * c] -= coeffs[i];
        }
    }
    return coeffs;
}

template<typename T>
void insertToDivisors(std::vector<std::vector<T>> &target, int x, T elem) {
    for (int r = 1; r * r <= x; r++) {
        if (x % r) continue;
        target[r].push_back(elem);
        if (x / r != r) {
            target[x / r].push_back(elem);
        }
    }
}

int countChildsOnTree(std::vector<std::vector<int>> &graph, int root, int par = -1) {
    int count = 1;
    for (auto &c : graph[root]) {
        if (par == c) continue;
        count += countChildsOnTree(graph, c, root);
    }
    return count;
}

std::pair<modint, modint> countPathAppearancesOnTree(std::vector<std::vector<int>> &graph, int i, int n, std::vector<bool> &visited) {
    modint totalCount = 0, totalChilds = 0;
    visited[i] = true;
    for (auto &c : graph[i]) {
        if (visited[c]) continue;
        auto [count, childs] = countPathAppearancesOnTree(graph, c, n, visited);
        totalCount += count + totalChilds * childs;
        totalChilds += childs;
    }

    totalCount += totalChilds * (n - 1 - totalChilds);
    totalCount += n - 1;
    totalChilds += 1;

    return {totalCount, totalChilds};
}

modint countPathAppearances(std::vector<std::vector<int>> &graph) {
    modint count = 0;

    int n = graph.size();
    std::vector visited(n, false);

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        std::queue<int> q;
        q.push(i);

        int m = countChildsOnTree(graph, i);
        count += countPathAppearancesOnTree(graph, i, m, visited).first;
    }

    return count;
}

int main() {
    auto coefs = calcCoefs();

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector groups(MAX, std::vector<int>());
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        insertToDivisors(groups, a[i], i);
    }

    std::vector edges(MAX, std::vector<std::pair<int, int>>());
    for (int i = 0, ui, vi; i < n-1; i++) {
        std::cin >> ui >> vi;
        ui--; vi--;
        insertToDivisors(edges, std::gcd(a[ui], a[vi]), {ui, vi});
    }

    modint ans = 0;

    for (int base = 1; base < MAX; base++) {
        std::unordered_map<int, int> zip;
        std::vector<int> unzip;
        int m = compress(groups[base], zip, unzip);

        std::vector graph(m, std::vector<int>());
        for (auto &[ui, vi] : edges[base]) {
            graph[zip[ui]].push_back(zip[vi]);
            graph[zip[vi]].push_back(zip[ui]);
        }

        ans += countPathAppearances(graph) * coefs[base];

        // if (!groups[base].empty()) {
        //     std::cerr << base << std::endl;
        //     for (auto &i : groups[base]) {
        //         std::cerr << i << ' ';
        //     }
        //     std::cerr << std::endl;
        //     std::cerr << coefs[base].val() << ' ' << (countPathAppearances(graph) * coefs[base]).val() << std::endl << std::endl;
        // }
    }

    std::cout << ans.val() << '\n';
    return 0;
}