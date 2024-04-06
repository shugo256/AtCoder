#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main()
{
    int h, w, r, c;
    std::cin >> h >> w >> r >> c;
    std::cout << int(r > 1) + int(c > 1) + int(r < h) + int(c < w) << '\n';
    return 0;
}