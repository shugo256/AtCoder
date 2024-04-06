#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <atcoder/lazysegtree>
#include <atcoder/modint>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

using mint = atcoder::modint998244353;

struct S {
    mint val;
    mint len;
};

S op(S l, S r){
    return S{l.val + r.val, l.len + r.len};
}

S e() { 
    return S{0, 0};
}

struct F {
    // (v, l) => (av + bl, l)
    mint a;
    mint b;
};

S mapping(F f, S s) {
    return S{f.a * s.val + f.b * s.len, s.len};
}

F composition(F l, F r) {
    return F{r.a * l.a, r.b * l.a + l.b};
}

F id() { return F{1, 0}; }


int main() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
    std::map<ll, int> mp;
    mp[0] = 0;
    for (auto &ai:a) {
        std::cin >> ai;
        mp[ai] = 0;
    }
    ll prev = -1;
    std::vector<S> base;
    int cnt = 0;
    for (auto &[key, val]:mp) {
        if (prev >= 0) {
            if (key <= a[0]) {
                base.push_back(S{key - prev, key - prev});
            } else {
                base.push_back(S{0, key - prev});
            }
        }
        prev = key;
        val = cnt;
        cnt++;
    }

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> sgt(base);

    // std::cerr << base.size() << std::endl;

    for (int i=1; i<n; i++) {
        int cur = mp[a[i]];
        mint sum = sgt.all_prod().val;
        sgt.apply(0, cur, F{-1, sum});
        sgt.apply(cur, base.size(), F{0, 0});
    }
    std::cout << sgt.all_prod().val.val() << '\n';
    
    return 0;
}