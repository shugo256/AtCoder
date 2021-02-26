#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        std::string s;
        std::cin >> s;
        int cnt = 0, last = 0, inb = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'a') {
                cnt++;
                last = i;
            } else {
                inb = cnt;
            }
        }
        if (cnt == s.size()) {
            std::cout << s << '\n';
        } else if (inb % 2 == 0) {
            std::cout << std::string(s.size() - cnt, 'b') + std::string(cnt - inb, 'a') << '\n';
        } else if (cnt - inb > 0) {
            std::cout << std::string(s.size() - cnt, 'b') + std::string(cnt - inb - 1, 'a') << '\n';
        } else {
            cnt--;
            std::string ans(s.size() - cnt, 'b');
            last = last - cnt;
            if (last >= s.size() - cnt - 3) {
                std::string ans(s.size() - cnt, 'b');
                ans[last] = 'a';
                std::cout << ans << '\n';
            } else {
                std::string ans(s.size() - cnt - 2, 'b');
                ans[ans.size() - 1] = 'a';
                std::cout << ans << '\n';
            }
        }

    }
    return 0;
}