#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int n;
    std::cin >> n;
    std::map<std::string, int> count;
    std::vector<std::pair<std::string, std::string>> names(n);
    for (auto &[first, family]:names) {
        std::cin >> first >> family;
        count[first]++;
        if (first != family) 
            count[family]++;
    }

    for (auto &[first, family] : names) {
        if (count[first] > 1 && count[family] > 1) {
            std::cout << "No" << '\n';
            return 0;
        }
    }

    std::cout << "Yes" << '\n';
    return 0;
}