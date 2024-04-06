#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

#define INF (int(1e9) + 10)

int main() {
    int n;
    std::cin >> n;
    int ans = INF;
    for (int i=0, ai, pi, xi; i<n; i++) {
        std::cin >> ai >> pi >> xi;
        if (ai < xi) amin(ans, pi);
    }
    std::cout << (ans < INF ? ans : -1) << '\n';
    return 0;
}