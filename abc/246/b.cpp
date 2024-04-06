#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    long double a, b;
    std::cin >> a >> b;
    long double l = std::hypotl(a, b);
    std::cout << std::fixed << std::setprecision(15) << a / l << ' ' << b / l << '\n';
    return 0;
}