#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

std::vector<int> solve(int n) {
    if (n == 1) {
        return {1};
    }
    auto subAns = solve(n - 1);

    std::vector<int> ans;
    ans.insert(ans.end(), subAns.begin(), subAns.end());
    ans.push_back(n);
    ans.insert(ans.end(), subAns.begin(), subAns.end());
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    for (auto &si : solve(n)) {
        std::cout << si << ' ';
    }
    std::cout << '\n';
    return 0;
}