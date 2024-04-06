#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>
#include <atcoder/dsu>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

using BS = std::bitset<20>;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<BS> answers(n);
    ll odd = 0, even = 0;
    for (auto &ai: answers) {
        std::cin >> ai;
        if (ai.count() % 2 == 0) even++;
        else odd++;
    }
    std::cout << even * odd << '\n';
    return 0;
}