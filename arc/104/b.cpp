#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

#define amax(a, b) a = max(a, b)
#define amin(a, b) a = min(a, b)

using ll = long long;

using P = std::pair<int, int>;
#define fi first
#define se second

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::map<P, int> mp;
    P now(0, 0);
    mp[now]++;
    int ans = 0;
    for (auto &c:s) {
        if (c == 'A')
            now.fi++;
        else if (c == 'T')
            now.fi--;
        else if (c == 'C')
            now.se++;
        else
            now.se--;
        ans += mp[now];
        mp[now]++;
    }
    std::cout << ans << '\n';
    return 0;
}