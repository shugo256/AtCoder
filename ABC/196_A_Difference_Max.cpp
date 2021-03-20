#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << b - c << '\n';
    return 0;
}