#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int x;
    std::cin >> x;
    std::cout << 100 - x % 100 << '\n';
    return 0;
}