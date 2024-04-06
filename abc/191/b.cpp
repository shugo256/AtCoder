#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> ans;
    for (int i=0, ai; i<n; i++) {
        std::cin >> ai;
        if (ai != x) ans.push_back(ai);
    }
    for (auto &ai:ans) {
        std::cout << ai << ' ';
    }
    std::cout << '\n';
    return 0;
}