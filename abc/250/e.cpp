#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }
    for (auto &bi : b) {
        std::cin >> bi;
    }

    std::vector<std::pair<int, int>> acceptableRanges(n, {-1, -1});
    std::unordered_set<int> aSet, bSet, diffSet;
    for (int aIdx = 0, bBegin = 0, bEnd = 0; aIdx < n; aIdx++) {
        if (aSet.count(a[aIdx]) == 0) {
            aSet.insert(a[aIdx]);
            if (diffSet.count(a[aIdx]) == 0) {
                diffSet.insert(a[aIdx]);
                for (bBegin = bEnd; bBegin < n && b[bBegin] != a[aIdx]; bBegin++) {
                    // if (bSet.count(b[bBegin])) continue;
                    bSet.insert(b[bBegin]);
                    if (diffSet.count(b[bBegin]) == 0) {
                        diffSet.insert(b[bBegin]);
                    } else {
                        diffSet.erase(b[bBegin]);
                    }
                }
                if (bBegin < n) {
                    bSet.insert(b[bBegin]);
                    diffSet.erase(b[bBegin]);
                }
                bEnd = bBegin;
            } else {
                diffSet.erase(a[aIdx]);
            }
            if (diffSet.empty()) {
                for ( ; bEnd < n && bSet.count(b[bEnd]); bEnd++);
            } else {
                bBegin = bEnd;
            }
        }
        // std::cerr << "hoge " << bBegin << ' ' << bEnd << std::endl;
        acceptableRanges[aIdx] = {bBegin, bEnd};
    }

    int q; std::cin >> q;
    for (int i = 0, xi, yi; i < q; i++) {
        std::cin >> xi >> yi;
        xi--; yi--;
        auto [begin, end] = acceptableRanges[xi];
        std::cout << (begin <= yi && yi < end ? "Yes" : "No") << '\n';
    }
    return 0;
}