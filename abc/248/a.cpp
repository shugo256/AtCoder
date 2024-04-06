#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    const std::string all("0123456789");
    std::set<char> st(all.begin(), all.end());
    std::string s;
    std::cin >> s;
    for (auto &c : s) {
        st.erase(c);
    }
    std::cout << *st.begin() << '\n';
    return 0;
}