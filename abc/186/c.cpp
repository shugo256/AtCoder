#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        std::stringstream so, sd;
        so << std::oct << i;
        sd << std::dec << i;
        std::string str = so.str() + sd.str();
        bool has7 = false;
        for (auto &c:str) {
            if (c == '7') {
                has7 = true;
            }
        }
        if (!has7) ans++;
    }
    std::cout << ans << '\n';
    return 0;
}