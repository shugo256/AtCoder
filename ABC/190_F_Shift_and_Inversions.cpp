#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/segtree>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int op(int a, int b) { return a + b; }
int e() { return 0; }

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &ai:a) std::cin >> ai;
    atcoder::segtree<int, op, e> seg(n);

    ll ans = 0;
    for (auto &ai:a) {
        ans += seg.prod(ai, n);
        seg.set(ai, 1);
    }

    for (auto &ai:a) {
        std::cout << ans << '\n';
        ans -= seg.prod(0, ai); // 先頭の自分の削除による転倒数を現社
        seg.set(ai, 0); // 先頭削除
        ans += seg.prod(ai, n); // 末尾の自分の追加による転倒数の増加
        seg.set(ai, 1); // 先頭追加
    }

    return 0;
}
