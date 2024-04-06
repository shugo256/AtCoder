#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <atcoder/modint>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;
using modint = atcoder::modint998244353;

constexpr ll MAX = 1e6 + 1;

int main() {
    std::vector<modint> c(MAX, 0);
    for (int i = 1; i < MAX; i++) {
        c[i] += modint(i).inv();
        for (int d = 2; i * d < MAX; d++) {
            c[i * d] -= c[i];
        }
    }

    int n;
    std::cin >> n;
    std::vector<modint> sums(MAX, 0);
    
    for (int i = 0, pi; i < n; i++) {
        std::cin >> pi;
        for (int r = 1; r * r <= pi; r++) {
            if (pi % r == 0) {
                sums[r] += pi;
                if (pi / r != r) {
                    sums[pi / r] += pi;
                }
            }
        }
    }

    modint ans = 0;
    for (int i = 1; i < MAX; i++) {
        ans += sums[i] * sums[i] * c[i];
    }
    ans = (ans - sums[1]) / 2;

    std::cout << ans.val() << '\n';
    return 0;
}