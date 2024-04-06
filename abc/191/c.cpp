#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int h, w;
    std::string s;
    std::cin >> h >> w >> s;

    int ans = 0;
    std::vector<bool> cur(w, false), prev(w, false);
    for (int i=1; i<h; i++) {
        std::cin >> s;
        for (int k=0; k<w; k++) 
            cur[k] = (s[k] == '#');
        
        for (int j=1; j<w; j++) {
                 if (!prev[j-1] && !prev[j] && !cur[j-1] &&  cur[j]) ans += 2;
            else if (!prev[j-1] && !prev[j] &&  cur[j-1] && !cur[j]) ans++;
            else if (!prev[j-1] &&  prev[j] && !cur[j-1] && !cur[j]) ans++;

            else if ( prev[j-1] &&  prev[j] &&  cur[j-1] && !cur[j]) ans += 2;
            else if ( prev[j-1] &&  prev[j] && !cur[j-1] &&  cur[j]) ans++;
            else if ( prev[j-1] && !prev[j] &&  cur[j-1] &&  cur[j]) ans++;
        }
        std::swap(cur, prev);
    }
    std::cout << ans << '\n';
    return 0;
}