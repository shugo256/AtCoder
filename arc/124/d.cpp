#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int countClosedLoops(std::vector<int> &p, int from, int to) {
    int count = 0;
    std::vector<bool> visited(to - from, false);
    for (int i = from; i < to; i++) {
        if (visited[i - from]) continue;
        visited[i - from] = true;

        if (p[i] == i) continue;

        int curPos = p[i];
        while (from <= curPos && curPos < to && !visited[curPos - from]) {
            visited[curPos - from] = true;
            curPos = p[curPos];
        }
        // std::cerr << i << ' ' << curPos << std::endl;

        if (curPos == i) {
            count++;
        }
    }

    return count;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> p(n + m);

    int matches = 0;
    for (int i = 0; i < n + m; i++) {
        std::cin >> p[i];
        p[i]--;
        if (i == p[i]) {
            matches++;
        }
    }

    int leftLoops = countClosedLoops(p, 0, n);
    int rightLoops = countClosedLoops(p, n, n+m);
    int crossingLoops = countClosedLoops(p, 0, n+m) - leftLoops - rightLoops;

    // std::cerr << matches << ' ' << leftLoops << ' ' << rightLoops << ' ' << crossingLoops << std::endl;

    std::cout << (n + m - matches) - crossingLoops + std::abs(leftLoops - rightLoops) << '\n';
    return 0;
}