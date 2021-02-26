#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = max(a, b)
#define amin(a, b) a = min(a, b)

using ll = long long;

int main() {
    int h, w;
    std::cin >> h >> w;
    std::string s[h];
    int ans = 0;
    for (int i=0; i<h; i++) {
        std::cin >> s[i];
        for (int j=0; j<w; j++) {
            if (s[i][j] == '#') continue;
            if (i > 0 && s[i-1][j] == '.') ans++;
            if (j > 0 && s[i][j-1] == '.') ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}