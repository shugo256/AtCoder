#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int dfs(std::vector<std::vector<int>> &tree, std::vector<bool> &isGoalNode, int i = 0, int par = -1) {
    int flipRequiredNodes = 0;
    for (auto &t : tree[i]) {
        if (t == par) continue;
        flipRequiredNodes += dfs(tree, isGoalNode, t, i);
    }
    // std::cerr << i << ' ' << std::max(flipRequiredNodes - 1, 0) + int(isGoalNode[i]) << std::endl;
    return std::max(flipRequiredNodes - 1, 0) + int(isGoalNode[i]);
}


int main() {
    int n;
    std::cin >> n;
    std::vector tree(n, std::vector<int>());
    std::vector a(n, 0);
    for (int i = 1; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0, ui, vi; i < n-1; i++) {
        std::cin >> ui >> vi;
        ui--; vi--;
        tree[ui].push_back(vi);
        tree[vi].push_back(ui);
    }
    int l = 0, r = *std::max_element(a.begin(), a.end()) + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        // std::cerr << m << std::endl;
        std::vector<bool> isGoalNode(n, false);
        for (int i = 0; i < n; i++) {
            isGoalNode[i] = (a[i] >= m);
        }
        if (dfs(tree, isGoalNode) > 0) {
            l = m;
        } else {
            r = m;
        }
    }
    std::cout << l << '\n';
    return 0;
}