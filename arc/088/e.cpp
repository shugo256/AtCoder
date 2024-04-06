#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <cassert>

using ll = long long;

using namespace std;

// 和以外はseg木でよくねという発想の元、和のみを実装
template <typename T>
class BIT {
    const int n;
    vector<T> tree;

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
        assert(0 <= a && a < n);
        T res = 0;
        for (int i = (int)a - 1; i >= 0; i = (i & (i + 1)) - 1)
            res += tree[(size_t)i];
        return res;
    }

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

using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int cnt[26] = {0};
    for (auto &c:s) cnt[c-'a']++;
    queue<int> pos[26];
    vector<P> r;
    int move[n], m=0;
    fill(move, move+n, -1);
    for (int i=0; i<n; i++) {
        int ci = s[i] - 'a';
        if (pos[ci].size() < cnt[ci] / 2) {
            pos[ci].push(m);
            move[i] = m;
            m++;
        }
        else
            r.push_back({ci, i});
    }
    reverse(r.begin(), r.end());
    bool even = (n%2 == 0);
    for (auto p:r) {
        if (pos[p.first].empty()) {
            if (even) {
                cout << -1 << '\n';
                return 0;
            }
            even = true;
            move[p.second] = n / 2;
        } else {
            int tar = pos[p.first].front();
            pos[p.first].pop();
            move[p.second] = n - 1 - tar;
        }
    }
    BIT<int> bit(n);
    long ans = 0;
    for (int i=0; i<n; i++) {
        ans += i - bit.sum(move[i]);
        bit.push(move[i]);
    }
    cout << ans << '\n';
    return 0;
}