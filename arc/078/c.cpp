#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

bool ask(std::string n) {
    std::cout << "? " << n << std::endl;
    char ans;
    std::cin >> ans;
    return ans == 'Y';
}

void answer(std::string n) {
    std::cout << "! " << n << std::endl;
}

std::pair<int, bool> askDigits() {
    int l = 1, r = 11;
    while (r - l > 1) {
        int m = (l + r) / 2;
        std::string powM(m, '0');
        powM[0] = '1';
        if (ask(powM)) {
            l = m;
        } else {
            r = m;
        }
    }
    if (l < 10) {
        return {l, false};
    }
    // if N = 10 ^ x
    l = 0, r = 10;
    while (r - l > 1) {
        int m = (l + r + 1) / 2;
        std::string powM(m, '2');
        if (ask(powM)) {
            r = m;
        } else {
            l = m;
        }
    }
    return {r, true};
}

int main() {
    auto [digits, isPowerOf10] = askDigits();
    
    std::string s(10, '0');
    s[0] = '1';
    if (isPowerOf10) {
        answer(s.substr(0, digits));
    }

    for (auto &c : s) {
        char l = c, r = '9' + 1;
        while (r - l > 1) {
            char m = (l + r) / 2;
            c = m;
            if (ask(s)) {
                r = m;
            } else {
                l = m;
            }
        }
        c = l;
    }
    answer(std::to_string(std::stoll(s) + 1).substr(0, digits));
    return 0;
}