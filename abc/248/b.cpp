#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    ll a, b, k;
    std::cin >> a >> b >> k;
    for (int i = 0; ; i++, a *= k) {
        if (a >= b) {
            std::cout << i << '\n';
            return 0;
        }
    }
    return 0;
}