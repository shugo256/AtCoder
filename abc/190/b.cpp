#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int n, s, d;
    std::cin >> n >> s >> d;
    for (int i=0, xi, yi; i<n; i++){
        std::cin >> xi >> yi;
        if (xi < s && yi > d) {
            std::cout << "Yes" << '\n';
            return 0;
        }
    }
    std::cout << "No" << '\n';
    return 0;
}