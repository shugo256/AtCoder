#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/dsu>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

struct edge {
    int to, idx;
};

bool makeNodeSorted(
        std::vector<std::vector<edge>> &graph, 
        std::vector<int> &p, 
        std::vector<bool> &visited,
        int target,
        int i,
        std::vector<int> &operations) {
    
    // std::cerr << i << ' ' <<p[i] << ' ' << target << std::endl;
    
    visited[i] = true;

    if (p[i] == target) {
        return true;
    }
    
    for (auto &[ngh, op] : graph[i]) {
        if (visited[ngh]) continue;
        if (makeNodeSorted(graph, p, visited, target, ngh, operations)) {
            operations.push_back(op);
            std::swap(p[i], p[ngh]);
            
            return true;
        }
    }

    return false;
}

bool sortConnectedComponent(
        std::vector<std::vector<edge>> &graph, 
        std::vector<int> &degree,
        std::vector<int> &p, 
        std::vector<int> &members,
        std::vector<int> &operations) {

    std::queue<int> sortables;
    for (auto &mi : members) {
        if (degree[mi] == 1) {
            sortables.push(mi);
        }
    }

    while (!sortables.empty()) {
        int i = sortables.front(); sortables.pop();
        // std::cerr << i << std::endl;

        std::vector<bool> visited;
        std::transform(degree.begin(), degree.end(), std::back_inserter(visited), [](int deg) {
            return deg == 0;
        });
        if (!makeNodeSorted(graph, p, visited, i, i, operations)) {
            return false;
        }

        for (auto &[ngh, _] : graph[i]) {
            if (degree[ngh] == 0) continue;
            degree[i]--;
            degree[ngh]--;
            if (degree[ngh] == 1) {
                sortables.push(ngh);
            }
        }
    }
    
    return true;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (auto &pi : p) {
        std::cin >> pi;
        pi--;
    }

    int m;
    std::cin >> m;

    atcoder::dsu dsu(n);
    std::vector degree(n, 0);
    std::vector graph(n, std::vector<edge>());
    for (int i = 0, ai, bi; i < m; i++) {
        std::cin >> ai >> bi;
        ai--; bi--;

        if (dsu.same(ai, bi)) continue;
        dsu.merge(ai, bi);
        degree[ai]++; degree[bi]++;
        graph[ai].push_back({bi, i + 1});
        graph[bi].push_back({ai, i + 1});
    }

    std::vector<int> operations;

    for (auto &group : dsu.groups()) {
        if (!sortConnectedComponent(graph, degree, p, group, operations)) {
            std::cout << -1 << '\n';
            return 0;
        }
    }

    std::cout << operations.size() << '\n';
    for (auto &oi : operations) {
        std::cout << oi << ' ';
    }
    std::cout << '\n';
    return 0;
}