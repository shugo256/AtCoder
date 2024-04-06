#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    std::bitset<4> n;
    std::cin >> n;
    std::cout << (n >> 1) << '\n';
    return 0;
}