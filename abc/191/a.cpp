#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int v, t, s, d;
    std::cin >> v >> t >> s >> d;
    std::cout << (v*t <= d && d <= v*s ? "No" : "Yes") << '\n';
    return 0;
}