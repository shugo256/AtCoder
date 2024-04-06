#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

bool dfs(std::vector<std::vector<int>>& graph, std::vector<int>& color,
         std::vector<bool>& visited, std::map<int, int>& depth, int i = 0,
         int par = -1, int loopStartDepth = 0, int lastDuplicateDepth = 0) {
  depth[i] = depth[par] + 1;
  visited[i] = true;
  if (par >= 0 && color[par] == color[i]) {
    loopStartDepth = lastDuplicateDepth;
    lastDuplicateDepth = depth[i];
  }
  for (auto g : graph[i]) {
    if (depth[g] > 0 && (depth[i] - depth[g]) % 2 == 0 &&
        loopStartDepth <= depth[g]) {
      return true;
    }
    if (!visited[g] && dfs(graph, color, visited, depth, g, i, loopStartDepth,
                           lastDuplicateDepth)) {
      return true;
    }
  }
  depth.erase(i);
  return false;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector graph(n, std::vector<int>());
  std::vector color(n, 0);
  for (int i = 0, ai, bi; i < m; i++) {
    std::cin >> ai >> bi;
    ai--;
    bi--;
    graph[ai].push_back(bi);
    graph[bi].push_back(ai);
  }
  for (auto& ci : color) {
    std::cin >> ci;
  }

  std::vector<bool> visited(n, false);
  std::map<int, int> depth;

  std::cout << (dfs(graph, color, visited, depth) ? "Yes" : "No") << '\n';
  return 0;
}