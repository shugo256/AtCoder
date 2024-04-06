#include <iostream>
#include <string>

bool isShiftedAbc(std::string s) {
    return s.size() == 3 && std::string("ABCAB").find(s) != std::string::npos;
}

std::string removeShiftedAbcs(std::string &s) {
    std::string result;
    for (auto &c : s) {
        result += c;
        if (int n = result.size(); n >= 3 && isShiftedAbc(result.substr(n - 3))) {
            result.erase(n - 3);
        }
    }
    return result;
}

int main() {
    int n;
    std::string s, t;
    std::cin >> n >> s >> t;
    std::cout << (removeShiftedAbcs(s) == removeShiftedAbcs(t) ? "YES" : "NO") << '\n';
    return 0;
}