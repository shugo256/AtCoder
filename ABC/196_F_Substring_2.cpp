#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/convolution>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    std::string s, t;
    std::cin >> s >> t;
    std::reverse(t.begin(), t.end());
    std::vector<ll> s_ll, t_ll, s_ll_rev, t_ll_rev;
    for (auto &si:s) {
        ll si_ll = si - '0';
        s_ll.push_back(si_ll);
        s_ll_rev.push_back(si_ll ^ 1ll);
    }
    for (auto &ti:t) {
        ll ti_ll = ti - '0';
        t_ll.push_back(ti_ll);
        t_ll_rev.push_back(ti_ll ^ 1ll);
    }

    auto one_zeros = atcoder::convolution_ll(s_ll, t_ll_rev);
    auto zero_ones = atcoder::convolution_ll(s_ll_rev, t_ll);

    ll ans = t.size();

    for (int i = t.size() - 1; i < s.size(); i++) {
        amin(ans, one_zeros[i] + zero_ones[i]);
    }
    
    std::cout << ans << '\n';
    return 0;
}