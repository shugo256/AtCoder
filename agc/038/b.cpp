#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <atcoder/segtree>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int max(int a, int b) {
    return std::max(a, b);
}

int min(int a, int b) {
    return std::min(a, b);
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> p(n);
    for (auto &pi : p) {
        std::cin >> pi;
    }

    std::vector<std::pair<int, int>> sortRange(n - k + 1, {0, 0});

    atcoder::segtree<int, max, std::numeric_limits<int>::min> maxSeg(p);
    for (int i = 0, sortEnd = 0; i < n; i++) {
        if (p[i] < maxSeg.prod(std::max(0, i + 1 - k), i + 1)) {
            sortEnd = i + 1;
        }
        if (i >= k - 1)
            sortRange[i - k + 1].second = sortEnd;
    }

    atcoder::segtree<int, min, std::numeric_limits<int>::max> minSeg(p);
    for (int i = n-1, sortStart = n - 1; i >= 0; i--) {
        if (p[i] > minSeg.prod(i, std::min(i + k, n))) {
            sortStart = i;
        }
        if (i < n - k + 1) {
            sortRange[i].first = sortStart;
            if (sortRange[i].first >= sortRange[i].second) {
                sortRange[i] = {0, 0};
            }
        }
    }

    // for (auto &[s, e] : sortRange) std::cerr << s << ' ' << e << std::endl;

    std::cout << std::set(sortRange.begin(), sortRange.end()).size() << '\n';
    return 0;
}