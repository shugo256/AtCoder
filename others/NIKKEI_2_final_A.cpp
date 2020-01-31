#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#include <functional>
#include <limits>

// i番目をxにかえるだけの関数(点更新のデフォルト) (i++はwarnig回避)
#define CHANGE_I [](int i, T x) { i++; return x; }
// i番目にxたす
#define ADD(sg) [&](int i, T x) { return sg[i] + x; }

template <typename T>
class SegmentTree {
    int n;                       // 葉の数
    T def;                 // 初期値 && 単位元
    vector<T> tree;              // 本体 
    function<T(T, T)> operation_f; // 区間クエリで使う処理
    function<T(int, T)> update_f;  // 点更新で使う処理 ただの変更の他、i番目にxをたすみたいなこともできる

    // 区間[a, b)の総和(と言うか総operation(は？))
    // ノードk=[l, r)を見ている
    T _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def;            // 全く交差しない場合
        if (a <= l && r <= b) return tree[(size_t)k]; // 完全に包含される場合
        T vl = _query(a, b, k * 2 + 1, l, (l + r) / 2),
          vr = _query(a, b, k * 2 + 2, (l + r) / 2, r);
        return operation_f(vl, vr);
    }

  public:
    SegmentTree(int _n, T _def, function<T(T, T)> _operation_f, function<T(int, T)> _update_f = CHANGE_I)
        : def(_def), operation_f(_operation_f), update_f(_update_f)  {
        n = 1;
        while (n < _n) n <<= 1;
        tree = vector<T>((size_t)(2*n - 1), def);
    }

    //よく使うやつら min, max, sum
    SegmentTree(int _n, T _def, string mode, function<T(int, T)> _update_f = CHANGE_I)
        : SegmentTree(
            _n, 
            _def,
            mode == "max" ? [](T l, T r) { return max(l, r); } :
           (mode == "min" ? [](T l, T r) { return min(l, r); } :
                            [](T l, T r) { return l + r; }), // sum
            _update_f
        ) {}

    SegmentTree(int _n, string mode, function<T(int, T)> _update_f = CHANGE_I)
        : SegmentTree(
            _n, 
            mode == "max" ? numeric_limits<T>::lowest() : 
           (mode == "min" ? numeric_limits<T>::max() :
                            0), // sum
            mode,
            _update_f
        ) {}

    template <typename ID>
    void update(ID i, T x) {
        T next_i = update_f((int)i, x);
        i += (ID)n - 1;
        tree[(size_t)i] = next_i;
        while (i > 0) {
            i = (i - 1) / 2;
            tree[(size_t)i] = operation_f(tree[(size_t)(i * 2 + 1)], tree[(size_t)(i * 2 + 2)]);
        }
    }

    template <typename ID1, typename ID2>
    T query(ID1 a, ID2 b) { return _query((int)a, (int)b, 0, 0, n); }

    void print_tree() {
        size_t next = 0, size = (size_t)(2 * n - 1);
        for (size_t i=0; i<size; i++) {
            cout << tree[i];
            if (i == next) {
                cout << '\n';
                next = (next + 1) * 2;
            } else 
                cout << string(size * 2 / (next+2), ' ');
        }
    }

    typename vector<T>::iterator begin() { return tree.begin() + n - 1; }
    typename vector<T>::iterator end() { return tree.end(); }

    T operator[](int i) { return tree[ (size_t)(i + n - 1) ]; }
};
/*
コンストラクタ
SegmentTree(n, def, op_func, [up_func])
SegmentTree(n, def, mode, [up_func])
SegmentTree(n, mode, [up_func])
*/

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
    int n;
    cin >> n;
    vector<ll> a(n), unzip;
    map<ll, int> zip;
    for (auto &ai:a) cin >> ai;
    int m = compress(a, zip, unzip);
    vector<int> idx[m];
    for (int i=0; i<n; i++) {
        idx[zip[a[i]]].push_back(i);
    }
    ll ans = 0;
    SegmentTree<ll> sgt(n, "sum");
    for (auto &idi:idx) {
        for (auto &i:idi) ans += sgt.query(0, i) * sgt.query(i+1, n);
        for (auto &i:idi) sgt.update(i, sgt[i]+1);
    }
    cout << ans << '\n';
    return 0;
}