#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/segtree>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

using S = ll;
ll op(ll a, ll b) {
    return std::min(a, b);
}
ll e() {
    return ll(1e15);
}

struct cost {
    ll a, b, c;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (auto &pi : p) {
        std::cin >> pi;
        pi--;
    }
    std::vector<cost> costs(n);
    ll aSum = 0, cSum = 0;
    for (auto &[ai, bi, ci] : costs) {
        std::cin >> ai >> bi >> ci;
        bi = std::min(ai, bi);
        ci = std::min(ai, ci);
        aSum += ai;
        cSum += ci;
    }

    std::vector<ll> startCosts(n);
    ll aRemainderSum = aSum, bCurSum = 0;
    for (int i = 0; i < n; i++) {
        aRemainderSum -= costs[i].a;
        startCosts[i] = bCurSum + aRemainderSum;
        // std::cerr << i << ' ' << startCosts[i] << std::endl;
        bCurSum += costs[i].b;
    }

    atcoder::segtree<S, op, e> seg(n);
    for (auto &pi : p) {
        ll best = seg.prod(0, pi);
        ll cost = std::min(startCosts[pi], best - costs[pi].a);
        if (cost < seg.get(pi)) {
            seg.set(pi, cost);
        }
    }

    ll cRemainderSum = cSum; aRemainderSum = aSum;
    for (int i = 0; i < n; i++) {
        aRemainderSum -= costs[i].a;
        cRemainderSum -= costs[i].c;
        seg.set(i, seg.get(i) - aRemainderSum + cRemainderSum);
        // std::cerr << i << ' ' << seg.get(i) << std::endl;
    }

    std::cout << seg.all_prod() << '\n';
    return 0;
}