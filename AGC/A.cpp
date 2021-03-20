#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/all>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::string s1, s2, s3;
        std::cin >> n >> s1 >> s2 >> s3;
        std::cout << std::string(1, '0') + std::string(n, '1') + std::string(n, '0') << '\n';
    }
    return 0;
}