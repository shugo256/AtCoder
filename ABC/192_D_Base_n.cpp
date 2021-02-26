#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    std::string x;
    ll m;
    std::cin >> x >> m;
    ll n = 0;
    for (auto &d:x)
        amax(n, (ll)d - '0');
    
    if (x.size() == 1) {
        std::cout << (x[0] - '0' <= m) << '\n';
        return 0;
    }

    ll left = n, right = m + 1, base;
    while (right - left > 1) {
        base = (left + right) / 2;
        // std::cerr << base << std::endl;

        ll total = 0;
        bool failed = false;
        for (auto &xic: x) {
            if (total > m / base) {
                failed = true;
                break;
            }
            total *= base;
            ll xi = xic - '0';
            total += xi;
        }
        if (failed || total > m) {
            right = base;
        } else {
            left = base;
        }
    }
    std::cout << left - n << '\n';
    return 0;
}