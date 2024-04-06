#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <cmath>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ld = long double;

constexpr ld EPS = 1e-10;

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<ld, ld>> points(n);
    for (auto &[xi, yi] : points) {
        std::cin >> xi >> yi;
    }
    ld l = 0, r = 100;
    while (r - l > EPS) {
        ld m = (l + r) / 2;

        // Node 0 & N+1 correspond to line y = 100 & y = -100 respectively
        std::vector graph(n + 2, std::vector<int>());
        for (int i = 0; i < n; i++) {
            auto [xi, yi] = points[i];
            if (100 - yi < m * 2) {
                graph[i+1].push_back(0);
                graph[0].push_back(i+1);
            }
            if (yi - (-100) < m * 2) {
                graph[i+1].push_back(n+1);
                graph[n+1].push_back(i+1);
            }

            for (int j = 0; j < i; j++) {
                auto [xj, yj] = points[j];
                if (std::hypotl(xi - xj, yi - yj) < m * 2) {
                    graph[i+1].push_back(j+1);
                    graph[j+1].push_back(i+1);
                }
            }
        }

        std::vector<bool> reachable(n+2, false);
        std::queue<int> q;
        reachable[0] = true;
        q.push(0);
        while (!q.empty()) {
            int f = q.front(); q.pop();
            for (auto &neighbor : graph[f]) {
                if (reachable[neighbor]) continue;
                reachable[neighbor] = true;
                q.push(neighbor);
            }
        }
        // std::cerr << m << ' ' << reachable[n+1] << std::endl;
        if (reachable[n+1]) {
            r = m;
        } else {
            l = m;
        }
    }

    std::cout << std::setprecision(15) << std::fixed << l << '\n';
    return 0;
}