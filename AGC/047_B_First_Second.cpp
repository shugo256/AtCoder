#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>

using ll = long long;

const std::string ALPHABET("abcdefghijklmnopqrstuvwxyz");

struct alph_cnt {
    std::vector<int> cnt;
    alph_cnt() : cnt(26, 0) {}
    int &operator[](char c) {
        return cnt[(size_t)(c - 'a')];
    }
};

int main() {
    int n;
    std::cin >> n;
    std::map<std::string, alph_cnt> m;
    int ans = 0;
    std::vector<std::string> s(n);
    for (auto &si:s) std::cin >> si;
    std::sort(s.begin(), s.end(), [](std::string &a, std::string &b){ return a.size() < b.size(); });
    for (auto &si:s) {
        std::reverse(si.begin(), si.end());
        alph_cnt cnt;
        for (auto &c:si) cnt[c]++;
        std::string cur;
        for (auto &c:si) {
            if (m.count(cur)) {
                alph_cnt &rec = m[cur];
                for (auto &al:ALPHABET) {
                    if (cnt[al] == 0) continue;
                    ans += rec[al];
                }
            }
            cur += c;
            cnt[c]--;
        }
        m[si.substr(0, si.size()-1)][si.back()]++;
        // std::cerr << si << ' ' << m[si.substr(0, si.size()-1)][si.back()] << std::endl;
    }
    std::cout << ans << '\n';
    return 0;
}