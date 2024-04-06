#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int q;
    std::cin >> q;
    std::queue<std::pair<ll, ll>> que;
    for (int i = 0, ti; i < q; i++) {
        std::cin >> ti;
        ll x, c;
        if (ti == 1) {
            std::cin >> x >> c;
            que.push({x, c});
        } else {
            std::cin >> c;
            ll sum = 0;
            while (!que.empty() && c >= que.front().second) {
                auto [xt, ct] = que.front(); que.pop();
                sum += xt * ct;
                c -= ct;
            }
            if (c > 0) {
                que.front().second -= c;
                sum += c * que.front().first;
            }
            std::cout << sum << '\n';
        }
    }
    return 0;
}