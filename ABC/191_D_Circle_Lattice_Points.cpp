#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <cassert>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;
using ld = long double;


#define RATIO (10000ll)
#define OFFSET (100000000000ll)

ll toLL(std::string &s) {
    int n = s.size(), zeros = 0;
    ll ans = 0;
    bool foundDot = false;
    for (int i=0; i<n || zeros > 0; i++, zeros = std::max(0, zeros-1)) {
        if (i < n) {
            if (s[i] != '.') {
                ans = ans * 10 + (s[i] - '0');
            }
            if (s[i] == '.' || (!foundDot && i == n-1)) {
                zeros = 5;
                foundDot = true;
            }
        } else {
            ans *= 10;
        }
    }
    return ans;
}


ll ceil(ll x) {
    return (x + RATIO - 1) / RATIO * RATIO;
}

int main() {
    std::string xs, ys, rs;
    std::cin >> xs >> ys >> rs;
    const ll x = toLL(xs) + OFFSET, y = toLL(ys) + OFFSET, r = toLL(rs);
    std::cerr << x << ' ' << y << ' ' << r << std::endl;
    
    ll ans = 0;
    for (ll i=ceil(x - r); i <= x + r; i += RATIO) {
        const ll dd = r * r - (i - x) * (i - x);

        ll left = y, right = y + r + 1;
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            if ((mid - y) * (mid - y) <= dd) {
                left = mid;
            } else {
                right = mid;
            }
        }
        ll max = left;


        left = y - r - 1, right = y;
        while (right - left > 1) {
            ll mid = (left + right + 1) / 2;
            if ((mid - y) * (mid - y) <= dd) {
                right = mid;
            } else {
                left = mid;
            }
        }
        ll min = right;

        ans += max / RATIO - (min - 1) / RATIO;
    }
    std::cout << ans << '\n';
    return 0;
}