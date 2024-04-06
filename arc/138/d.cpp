#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

std::vector<int> genKpopBases(int n, int k) {
    std::vector<int> bases;
    for (int i = 0; i < n; i++) {
        int baseBase = (1 << (i < k - 1 ? k + 1 : k - 1)) - 1;
        bases.push_back(baseBase ^ (1 << i));
    }
    return bases;
}

std::vector<int> genGrayCodeIndices(int n) {
    if (n == 0) {
        return std::vector<int>();
    }

    auto subGrayCodeIndices = genGrayCodeIndices(n - 1);
    std::vector<int> grayCodeIndices;
    grayCodeIndices.insert(grayCodeIndices.end(), subGrayCodeIndices.begin(), subGrayCodeIndices.end());
    grayCodeIndices.push_back(n - 1);
    grayCodeIndices.insert(grayCodeIndices.end(), subGrayCodeIndices.rbegin(), subGrayCodeIndices.rend());

    return grayCodeIndices;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    if ((n == k && k > 1) || k % 2 == 0) {
        std::cout << "No" << '\n';
        return 0;
    }

    std::cout << "Yes" << '\n';

    int pi = 0;
    auto bases = genKpopBases(n, k);
    // for (auto &bi : bases) std::cerr << std::bitset<10>(bi) << ' ' << bi << std::endl;
    // for (auto &gi : genGrayCodeIndices(n)) {
    //     std::cerr << gi << std::endl;
    // }
    for (auto &gi : genGrayCodeIndices(n)) {
        std::cout << pi << ' ';
        pi ^= bases[gi];
    }
    std::cout << pi << '\n';
    return 0;
}