#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <numeric>
#include <bitset>
#include <complex>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ld = long double;

constexpr ld EPS = 1e-10;

inline ld dot(std::complex<ld> a, std::complex<ld> b)   { return a.real() * b.real() + a.imag() * b.imag(); }
inline ld cross(std::complex<ld> a, std::complex<ld> b) { return a.real()* b.imag() - a.imag() * b.real(); }

ld distance_l_p(std::complex<ld> lineA, std::complex<ld> lineB, std::complex<ld> point) {
    return std::abs(cross(lineB-lineA, point-lineA)) / std::abs(lineB-lineA);
}

int main() {
    int n, k;
    std::cin >> n >> k;
    if (k == 1) {
        std::cout << "Infinity" << '\n';
        return 0;
    }

    std::vector<std::complex<ld>> points(n);
    for (auto &pi:points) {
        ld x, y;
        std::cin >> x >> y;
        pi = {x, y};
    }
    std::vector<std::bitset<300>> done(n, 0);
    std::vector count(n, std::vector(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (done[i][j]) continue;
            std::bitset<300> mask;
            mask.set(i);
            mask.set(j);
            count[i][j] = 2;
            for (int l = j + 1; l < n; l++) {
                if (distance_l_p(points[i], points[j], points[l]) < EPS) {
                    mask.set(l);
                    count[i][j]++;
                }
            }
            for (int l = 0; l < n; l++) {
                if (mask[l]) {
                    done[l] |= mask;
                }
            }
            // std::cerr << i << ' ' << j << ' ' << count[i][j] << std::endl;
        }
    }
    std::cout << std::accumulate(count.begin(), count.end(), 0, [&](int acc, const std::vector<int> &ci) {
        return acc + std::count_if(ci.begin(), ci.end(), [&](int a) {
            return a >= k;
        });
    }) << '\n';
    return 0;
}