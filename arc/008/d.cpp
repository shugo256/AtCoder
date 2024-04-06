#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <numeric>

using namespace std;

#include <functional>
#include <limits>

template <typename T>
class SegmentTree {
    int n;                       // 葉の数
    T def;                 // 初期値 && 単位元
    vector<T> tree;              // 本体 
    function<T(T, T)> operation_f, // 区間クエリで使う処理
                      update_f;    // 点更新で使う処理 ただの変更の他、i番目にxをたすみたいなこともできる

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
    SegmentTree(int _n, T _def, function<T(T, T)> _operation_f, function<T(T, T)> _update_f)
        : def(_def), operation_f(_operation_f), update_f(_update_f)  {
        n = 1;
        while (n < _n) n <<= 1;
        tree = vector<T>((size_t)(2*n - 1), def);
    }

    // operation == update ver
    SegmentTree(int _n, T _def, function<T(T, T)> _f)
        : SegmentTree(_n, _def, _f, [](T l, T r) { return r; }) {}

    //よく使うやつら min, max, sum
    SegmentTree(int _n, T _def, string mode)
        : SegmentTree(
            _n, 
            _def,
            mode == "max" ? [](T l, T r) { return max(l, r); } :
           (mode == "min" ? [](T l, T r) { return min(l, r); } :
                            [](T l, T r) { return l + r; }) // sum
        ) {}

    SegmentTree(int _n, string mode)
        : SegmentTree(
            _n, 
            mode == "max" ? numeric_limits<T>::lowest() : 
           (mode == "min" ? numeric_limits<T>::max() :
                            0), // sum
            mode
        ) {}

    template <typename ID>
    void update(ID i, T x) {
        i += (ID)n - 1;
        tree[(size_t)i] = update_f(tree[(size_t)i], x);
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

    typename vector<T>::iterator begin() { return tree.begin() + (size_t)(n - 1); }
    typename vector<T>::iterator end() { return tree.end(); }

    T operator[](int i) { return tree[ (size_t)(i + n - 1) ]; }
};
/*
コンストラクタ
SegmentTree(n, def, op_func, up_func)
SegmentTree(n, def, op_func) -> up_funcは"i番目をxにそのまま変える"
SegmentTree(n, def, mode)
SegmentTree(n, mode)
*/

using ll = long;

#include <set>
#include <map>
// vecのなかの全要素について座標圧縮を行い、元座標->圧縮後座標というmapを作る
// O(NlogN) 座圧後のサイズを返す
//org: もともとの各iに対する座標 値渡しなので破壊しません
//zip: 圧縮
//unzip: 復元
int compress(vector<ll> org, map<ll, int> &zip, vector<ll> &unzip) {
    sort(org.begin(), org.end()); // vecの各要素を小さい順に重複を無くして並べたもの
    org.erase(unique(org.begin(), org.end()), org.end());
    int i=0;
    for (auto &oi:org) {
        zip[oi] = i;
        unzip.push_back(oi);
        i++;
    }
    return i;
}

using P = pair<double, double>;

int main() {
    long n;
    int m;
    cin >> n >> m;
    long ids[m];
    P ab[m];
    for (int i=0; i<m; i++) 
        cin >> ids[i] >> ab[i].first >> ab[i].second;
    vector<long> org(ids, ids + m), unzip;
    map<long, int> zip;
    int len = compress(org, zip, unzip);
    double ma = 1, mi = 1;
    SegmentTree<P> sg(len, P{1, 0}, [](P l, P r) {
        return P{l.first * r.first, r.first * l.second + r.second};
    });
    for (int i=0; i<m; i++) {
        sg.update(zip[ids[i]], ab[i]);
        P total = sg.query(0, len);
        double upd = total.first + total.second;
        ma = max(ma, upd);
        mi = min(mi, upd);
    }
    cout << fixed << setprecision(15) << mi << '\n' << ma << '\n';
    return 0;
}