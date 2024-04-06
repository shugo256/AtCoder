#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }
    int firstHalfEnd = 0;
    for ( ; firstHalfEnd < n; firstHalfEnd++) {
        if (a[firstHalfEnd] != firstHalfEnd % 2) {
            break;
        }
    }

    int secondHalfStart = n;
    for (int switches = 0, cur = 0; switches <= firstHalfEnd && secondHalfStart > 0; secondHalfStart--) {
        if (a[secondHalfStart - 1] != cur) {
            switches++;
            cur = a[secondHalfStart - 1];
            if (switches > firstHalfEnd) break;
        }
    }

    // std::cerr << firstHalfEnd << ' ' << secondHalfStart << std::endl;

    std::cout << (firstHalfEnd >= secondHalfStart ? "Yes" : "No") << '\n';
    return 0;
}