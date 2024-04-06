#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <numeric>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n), ainv(n);
    std::iota(a.begin(), a.end(), 0);
    std::iota(ainv.begin(), ainv.end(), 0);

    for (int i = 0, xi; i < q; i++) {
        std::cin >> xi;
        xi--;
        int pos = ainv[xi];
        int nextPos = pos + 1 < n ? pos + 1 : pos - 1;
        std::swap(a[pos], a[nextPos]);
        std::swap(ainv[a[pos]], ainv[a[nextPos]]);
    }

    for (auto &ai : a) {
        std::cout << ai + 1 << ' ';
    }
    std::cout << '\n';
    return 0;
}