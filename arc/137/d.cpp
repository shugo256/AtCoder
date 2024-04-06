#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <numeric>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

std::vector<int> fractalXor(std::vector<int> &org, int start, int d) {
    if (d == 0) {
        return {start < org.size() ? org[start] : 0};
    }
    int n = (1 << (d - 1));
    auto firstHalf = fractalXor(org, start, d - 1);
    auto secondHalf = fractalXor(org, start + n, d - 1);

    std::vector<int> result(firstHalf.begin(), firstHalf.end());
    for (int i = 0; i < n; i++) {
        result.push_back(firstHalf[i] ^ secondHalf[i]);
    }

    return result;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;
    std::reverse(a.begin(), a.end());

    int d = 0;
    for ( ; (1 << d) <= n; d++);
    auto ans = fractalXor(a, 0, d);
    std::reverse(ans.begin(), ans.end());

    for (int i = 0; i < m; i++) {
        std::cout << ans[i % ans.size()] << ' ';
    }

    std::cout << '\n';
    return 0;
}