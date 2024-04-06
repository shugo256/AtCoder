#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/segtree>
#include <atcoder/modint>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

using modint = atcoder::modint998244353;

int max(int a, int b) {
    return std::max(a, b);
}

int min(int a, int b) {
    return std::min(a, b);
}

int zero() {
    return 0;
}

int inf() {
    return int(1e9) + 1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }

    atcoder::segtree<int, max, zero> maxSeg(a);
    atcoder::segtree<int, min, inf> minSeg(a);
    modint ans = 0;

    for (int i = 0; i < n; i++) {
        int maxRangeBegin = maxSeg.min_left(i, [&](int x) { return x < a[i]; });
        int maxRangeEnd = maxSeg.max_right(i, [&](int x) { return x <= a[i]; });
        int minRangeBegin = minSeg.min_left(i, [&](int x) { return x > a[i]; });
        int minRangeEnd = minSeg.max_right(i, [&](int x) { return x >= a[i]; });
        std::cerr << maxRangeBegin << ' ' << maxRangeEnd << ' ' << minRangeBegin << ' ' << minRangeEnd << std::endl;

        auto calcCoef = [&](int begin, int end) {
            return (modint(2).pow(i) - (begin > 0 ? modint(2).pow(begin - 1) : 0)) 
                * (modint(2).pow(n - 1 - i) - (end < n ? modint(2).pow(n - 1 - end) : 0));
        };
        auto maxCoef = calcCoef(maxRangeBegin, maxRangeEnd);
        auto minCoef = calcCoef(minRangeBegin, minRangeEnd);

        std::cerr << maxCoef.val() << ' ' << minCoef.val() << std::endl;
        ans += (maxCoef - minCoef) * a[i];
    }

    std::cout << ans.val() << '\n';
    return 0;
}