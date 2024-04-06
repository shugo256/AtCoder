#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

using P = std::pair<int, int>;
#define fi first
#define se second

int main() {
    int n, m, k;
    std::cin >> n >> m;
    std::vector<P> conds(m);
    for (auto &ci:conds) {
        std::cin >> ci.fi >> ci.se;
        ci.fi--; ci.se--;
    }

    std::cin >> k;
    std::vector<P> people(k);
    for (auto &pi:people) {
        std::cin >> pi.fi >> pi.se;
        pi.fi--; pi.se--;
    }

    int ans = 0;
    for (int i=0; i<(1 << k); i++) {
        std::vector plates(n, false);
        for (int j=0; j<k; j++) {
            if (i & (1 << j)) {
                plates[people[j].fi] = true;
            } else {
                plates[people[j].se] = true;
            }
        }
        int sum = 0;
        for (auto &ci:conds) {
            if (plates[ci.fi] && plates[ci.se]) 
                sum++;
        }
        amax(ans, sum);
    }
    std::cout << ans << '\n';
    return 0;
}