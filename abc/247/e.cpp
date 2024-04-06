#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }
    a.push_back(0);
    std::vector<std::pair<ll, ll>> ranges;
    for (ll i = 0, start = 0; i < a.size(); i++) {
        if (a[i] < y || x < a[i]) {
            if (start < i) {
                ranges.push_back({start, i});
            }
            start = i + 1;
        }
    }

    ll ans = 0;
    for (auto &[start, end] : ranges) {
        ll foundX = -1, foundY = -1;
        for (ll curStart = start; curStart < end; ) {
            for (ll i = curStart; i < end && (foundX < curStart || foundY < curStart); i++) {
                // std::cerr << i << ' ' << curStart << ' ' << start << ' ' << end << std::endl;
                if (a[i] == x) {
                    foundX = i;
                }
                if (a[i] == y) {
                    foundY = i;
                }
            }
            if (foundX < curStart || foundY < curStart) {
                break;
            }
            ll guardStart = std::min(foundX, foundY);
            ll guardEnd = std::max(foundX, foundY);
            // std::cerr << guardStart << ' ' << guardEnd << std::endl;

            ans += (guardStart - curStart + 1) * (end - guardEnd);
            curStart = guardStart + 1;
        }
    }

    std::cout << ans << '\n';
    return 0;
}