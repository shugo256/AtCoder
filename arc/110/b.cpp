#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    ll n;
    std::string t;
    std::cin >> n >> t;
    std::string base("110");
    ll ans = 0;
    for (int off=0; off<3; off++) {
        bool yes = true;
        for (int i=0, o=off; i<n; i++, o++, o%=3) {
            // std::cerr << t[i] << ' ' << base[o] << std::endl;
            if (t[i] != base[o]) {
                yes = false;
                break;
            }
        }
        if (yes) ans += (ll(1e10) * 3 - off - n) / 3 + 1;
    }
    std::cout << ans << '\n';
    return 0;
}