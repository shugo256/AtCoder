#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    std::string s;
    std::cin >> s;
    std::reverse(s.begin(), s.end());
    char prev = '\0';
    ll ans = 0;
    std::vector cnt(26, 0);
    for (int i=0; i<s.size(); i++) {
        cnt[s[i] - 'a']++;
        if (s[i] == prev) {
            ans += i + 1 - cnt[s[i] - 'a'];
            fill(cnt.begin(), cnt.end(), 0);
            cnt[s[i] - 'a'] = i + 1;
        }
        prev = s[i];
    }
    std::cout << ans << '\n';
    return 0;
}