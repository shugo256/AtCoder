#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/modint>
#include <atcoder/dsu>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;
using modint = atcoder::modint998244353;

int main() {
    int n;
    std::cin >> n;
    std::vector<modint> line(n + 1, 0);
    line[0] = 1;
    for (int i = 1; i <= n; i++) {
        line[i] += (i > 0 ? line[i - 1] : 1);
        line[i] += (i > 1 ? line[i - 2] : 1);
        // std::cerr << line[i].val() << std::endl;
    }

    std::vector<int> p(n), q(n);
    for (auto &pi : p) std::cin >> pi;
    for (auto &qi : q) std::cin >> qi;
    atcoder::dsu dsu(n);
    for (int i = 0; i < n; i++) {
        dsu.merge(p[i] - 1, q[i] - 1);
    }

    modint ans = 1;
    for (auto &g : dsu.groups()) {
        int loopSize = g.size();
        modint sum = 0;
        sum += line[loopSize - 1];
        if (loopSize > 2) {
            sum += line[loopSize - 3];
        } else if (loopSize == 2) {
            sum += 1;
        }
        ans *= sum;
    }
    
    std::cout << ans.val() << '\n';
    return 0;
}