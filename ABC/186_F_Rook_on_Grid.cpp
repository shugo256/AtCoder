#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

// 和以外はseg木でよくねという発想の元、和のみを実装
#include <cassert>
template <typename T>
class BIT {
    const int n;
    std::vector<T> tree;

public:
    BIT(int _n) : n(_n), tree((size_t)_n, 0) {}

    // v[a] += w
    template <typename ID>
    void add(ID a, T w) {
        assert(0 <= a && a < n);
        for (int i = (int)a; i < n; i |= (i + 1)) 
            tree[(size_t)i] += w;
    }

    // v[0] + v[1] + ... + v[a-1]
    template <typename ID>
    T sum(ID a) {
        assert(0 <= a && a <= n);
        T res = 0;
        for (int i = (int)a - 1; i >= 0; i = (i & (i + 1)) - 1)
            res += tree[(size_t)i];
        return res;
    }

    // 総和
    T sum() { return sum(n); }

    // v[0] + v[1] + ... + v[a] >= w なる最小のa
    int lower_bound(T w) {
        int x = 0, beki = 1;
        for (int _n=n; _n>0; _n>>=1) beki <<= 1;
        for (int k=beki; k>0; k>>=1) {
            if (x + k <= n && tree[(size_t)(x + k - 1)] < w) {
                w -= tree[(size_t)(x + k - 1)];
                x += k;
            }
            //cerr << k << ' ' << x << ' ' << tree[x] << '\n';
        }
        return x;
    }

    // set(被りなし)としての機能を見やすく
    // ただし同じものをたとえば二回pushする場合、値が+2となって一回のpopでは消えないというバグあり
    template <typename ID>
    void push(ID a) { add(a, 1); }

    template <typename ID>
    void pop(ID a) { add(a, -1); }
};

int main() {
    int h, w, m;
    std::cin >> h >> w >> m;
    std::vector<int> x2y(h, w), y2x(w, h);
    int minh = h, minw = w;
    for (int i=0, xi, yi; i<m; i++) {
        std::cin >> xi >> yi;
        xi--; yi--;
        amin(x2y[xi], yi);
        amin(y2x[yi], xi);
        if (xi == 0) amin(minw, yi);
        if (yi == 0) amin(minh, xi);
    }
    ll ans = 0;
    int now = 0;
    std::vector pos(w+1, std::vector<int>());
    for (int i=0; i<minh; i++) {
        ans += x2y[i];
        pos[x2y[i]].push_back(i);
    }
    BIT<int> bit(h);
    for (int j=w; j>0; j--) {
        for (auto &xi:pos[j]) {
            bit.push(xi);
        }
        if (j <= minw)
            ans += y2x[j-1] - bit.sum(y2x[j-1]);
    }
    std::cout << ans << '\n';
    return 0;
}