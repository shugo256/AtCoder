#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

// 和以外はseg木でよくねという発想の元、和のみを実装
#include <cassert>
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
            cerr << k << ' ' << x << ' ' << tree[x] << '\n';
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

#include <map>
#include <set>
// vecのなかの全要素について座標圧縮を行い、元座標->圧縮後座標というmapを作る
// O(NlogN) 座圧後のサイズを返す
// org: もともとの各iに対する座標 値渡しなので破壊しません
// zip: 圧縮
// unzip: 復元
template <typename T>
int compress(vector<T> org, map<T, int> &zip, vector<T> &unzip) {
    sort(org.begin(), org.end()); 
    org.erase(unique(org.begin(), org.end()), org.end()); // vecの各要素を小さい順に重複を無くして並べたもの
    int i = 0;
    for (auto &oi : org) {
        zip[oi] = i;
        unzip.push_back(oi);
        i++;
    }
    return i;
}

int main() {
    long n;
    cin >> n;
    vector<long> a(n);
    for (auto &ai:a)
        cin >> ai;
    map<long, int> zip;
    vector<long> unzip;
    int k = compress(a, zip, unzip);
    int l = -1, r = k-1;
    while (r - l > 1) {
        int m = (l + r + 1) / 2,
            med = unzip[m];
        int rui = n;
        BIT<int> bit(2*n+1);
        bit.add(n, 1);
        long score = 0;
        // cerr << med << '\n' << rui;
        for (auto &ai:a) {
            if (ai > med) rui--;
            else rui++;
            bit.add(rui, 1);
            score += bit.sum(rui);
            // cerr << ' ' << rui;
        }
        // cerr << '\n' << score << '\n' << '\n';
        if (score >= (n * (n+1) / 2) / 2 + 1) r = m;
        else l = m;
    }
    cout << unzip[r] << '\n';
    return 0;
}