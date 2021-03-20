#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    std::string s, t;
    std::cin >> s >> t;
    std::string concat = s + '$' + t;
    auto sa = atcoder::suffix_array(concat);
    auto lcp = atcoder::lcp_array(concat, sa);
    // std::cerr << concat << std::endl;
    // for (auto &sai:sa) std::cerr << sai << ' ';
    // std::cerr << std::endl;
    // for (auto &lcpi:lcp) std::cerr << lcpi << ' ';
    // std::cerr << std::endl;
    int ans = t.size();
    for (int i=0; i<lcp.size(); i++) {
        ll min = std::min(sa[i], sa[i+1]);
        ll max = std::max(sa[i], sa[i+1]);
        if (min < s.size() && max > s.size() ) {
            std::cerr << i << ' ' << lcp[i] << std::endl;
            amin(ans, int(t.size() - lcp[i]));
        }
    }
    std::cout << ans << '\n';
    return 0;
}