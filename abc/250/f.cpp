#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

ll cross(std::pair<ll, ll> a, std::pair<ll, ll> b) { return a.first * b.second - a.second * b.first; }

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<ll, ll>> points(n);
    for (auto &[xi, yi] : points) {
        std::cin >> xi >> yi;
    }
    for (int i = 0; i < n; i++) points.push_back(points[i]);

    ll doubledTotalArea = 0;
    for (int i = 0; i < n; i++) {
        doubledTotalArea += cross(points[i], points[i + 1]);
    }
    doubledTotalArea = std::abs(doubledTotalArea);
    // std::cerr << doubledTotalArea << std::endl;

    ll ans = doubledTotalArea;
    ll doubledArea = 0;
    for (int begin = 0, end = 1; begin < n; begin++) {
        if (end - begin >= 3)
            amin(ans, std::abs(doubledTotalArea - std::abs(doubledArea) * 4));
            // std::cerr << begin << ' ' << end << ' ' << doubledArea << std::endl;
        for ( ; end - begin < 3 || std::abs(doubledArea) * 4 < doubledTotalArea; end++) {
            doubledArea -= cross(points[end - 1], points[begin]);
            doubledArea += cross(points[end - 1], points[end]);
            doubledArea += cross(points[end], points[begin]);
            if (end + 1 - begin >= 3)
                amin(ans, std::abs(doubledTotalArea - std::abs(doubledArea) * 4));
            // std::cerr << begin << ' ' << end << ' ' << doubledArea << std::endl;
        }
        doubledArea -= cross(points[end - 1], points[begin]);
        doubledArea -= cross(points[begin], points[begin + 1]);
        doubledArea += cross(points[end - 1], points[begin + 1]);
    }
    std::cout << ans << '\n';
    return 0;
}