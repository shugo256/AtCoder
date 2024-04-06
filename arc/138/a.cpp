#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }
    for (int i = k, prev = 0; i < n; i++) {
        amax(a[i], prev);
        prev = a[i];
    }
    int minOp = n + 1;
    for (int i = 0; i < k; i++) {
        auto iter = std::upper_bound(a.begin() + k, a.end(), a[i]);
        if (iter != a.end()) {
            amin(minOp, int(iter - a.begin()) - i);
        }
    }
    std::cout << (minOp < n ? minOp : -1) << '\n';
    return 0;
}