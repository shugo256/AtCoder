#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = max(a, b)
#define amin(a, b) a = min(a, b)

using ll = long long;

int main() {
    char s, t;
    std::cin >> s >> t;
    if (s == 'Y') t -= 32;
    std::cout << t << '\n';
    return 0;
}