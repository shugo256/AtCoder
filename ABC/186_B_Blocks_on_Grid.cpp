#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int h, w;
    std::cin >> h >> w;
    int sum = 0, min = 100;
    for (int i=0, aij; i<h*w; i++) {
        std::cin >> aij;
        sum += aij;
        amin(min, aij);
    }
    std::cout << sum - min * w * h << '\n';
    return 0;
}