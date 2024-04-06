#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

ll median(std::vector<ll> v) {
    std::sort(v.begin(), v.end());
    return v[v.size() / 2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
    ll snukeSum = 0;
    for (auto &ai : a) {
        std::cin >> ai;
        snukeSum += ai;
    }
    std::vector<int> isSmallHalf(n, 0);
    int med = median(a);
    int medCnt = 0;
    std::vector<int> medIdxs;
    for (int i = 0; i < n; i++) {
        if (a[i] < med) {
            isSmallHalf[i] = 1;
            medCnt++;
            snukeSum -= a[i];
        } else if (a[i] == med) {
            medIdxs.push_back(i);
        }
    }
    for (int i = 0; medCnt + i < n / 2; i++) {
        isSmallHalf[medIdxs[i]] = 1;
        snukeSum -= a[medIdxs[i]];
    }
    std::vector<int> height(n*2 + 1, 0);
    for (int i = 0; i < n*2; i++) {
        height[i + 1] = height[i] + (isSmallHalf[i % n] ? 1 : -1);
    }
    int k = std::min_element(height.begin(), height.begin() + n) - height.begin();

    std::cout << k << ' ' << snukeSum << '\n';
    return 0;
}