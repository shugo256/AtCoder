#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

constexpr ll INF = 1000000010;

int main() {
    int n;
    std::cin >> n;
    ll begin = -INF, end = +INF;
    ll offset = 0;
    for (int i=0, ai, ti; i<n; i++) {
        std::cin >> ai >> ti;
        if (ti == 1) {
            offset += ai;
        } else if (ti == 2) {
            amax(begin, ai - offset);
            amax(end, ai - offset);
        } else {
            amin(begin, ai - offset);
            amin(end, ai - offset);
        }
    }
    // std::cerr << begin << ' ' << end << ' '<< offset << std::endl;
    int q; std::cin >> q;
    for (int i=0; i<q; i++) {
        ll xi;
        std::cin >> xi;
        amax(xi, begin);
        amin(xi, end);
        std::cout << xi + offset << '\n';
    }
    return 0;
}