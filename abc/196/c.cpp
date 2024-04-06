#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    std::string n;
    std::cin >> n;
    int l = n.size();
    if (l % 2 == 0) {
        int first_half = std::stoi(n.substr(0, l/2));
        int second_half = std::stoi(n.substr(l/2));

        std::cout << (first_half <= second_half ? first_half : first_half - 1) << '\n';
    } else {
        std::cout << std::stoi(std::string(1, '1') + std::string(l / 2, '0')) - 1 << std::endl;
    }
    return 0;
}