#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    ll b, c;
    std::cin >> b >> c;
    ll pma, pmi, mma, mmi;
    if (b > 0) {
        pma = b + (c - 2) / 2;
        pmi = b - c / 2;
        mma = -b + (c - 1) / 2;
        mmi = -b - (c - 1) / 2;
    } else {
        pma = -b + (c - 1) / 2;
        pmi = -b - (c - 1) / 2;
        mma = b + (c - 2) / 2;
        mmi = b - c / 2;
    }
    std::cout << (mma < pmi ? pma - pmi + mma - mmi + 2 : std::max(pma, mma) - std::min(pmi, mmi) + 1) << '\n';
    return 0;
}