#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/math>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;


int main() {
    int T;
    std::cin >> T;
    while (T--) {
        ll X, Y, P, Q;
        std::cin >> X >> Y >> P >> Q;
        ll N = (X + Y) * 2, M = (P + Q);
        const ll inf = N * M;
        ll ans = inf;
        for (ll y=0; y<Y; y++) {
            ll yoff = X + y;
            for (ll q=0; q<Q; q++) {
                ll qoff = P + q;
                auto [len, lcm] = atcoder::crt({yoff, qoff}, {N, M});
                if (lcm == 0) continue;
                amin(ans, len);
            }
        }
        std::cout << (ans < inf ? std::to_string(ans) : std::string("infinity")) << '\n';
        // std::cerr << std::endl;
    }
    return 0;
}