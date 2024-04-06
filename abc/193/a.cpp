#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    double a, b;
    std::cin >> a >> b;
    std::cout << (a - b) / a * 100 << '\n';
    return 0;
}