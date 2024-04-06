#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = max(a, b)
#define amin(a, b) a = min(a, b)

using ll = long long;

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << (a + b) / 2 << ' ' << (a - b) / 2 << '\n';
    return 0;
}