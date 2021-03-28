#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <atcoder/modint>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

using mint = atcoder::modint998244353;

using P = std::pair<ll, int>;
#define fi first
#define se second

int main() {
    int n;
    std::cin >> n;
    std::map<ll, int> cnt;
    for (int i=0; i<n; i++) {
        ll ai;
        std::cin >> ai;
        cnt[ai]++;
    }
    mint sum = 0, ans = 0;
    for (auto &[key, val]:cnt) {
        mint pow = mint(2).pow(val);
        mint selfMin = (pow - 1) * key;
        ans += sum * (pow - 1) * key + mint(key) * selfMin;
        sum = sum * pow + selfMin;
    }
    std::cout << ans.val() << '\n';
    return 0;
}