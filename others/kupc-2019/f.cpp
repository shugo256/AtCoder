#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

#define maximize(a, b) a = max(a, b)

#include <functional>
#include <limits>

// i番目をxにかえるだけの関数(点更新のデフォルト) (i++はwarnig回避)
#define CHANGE_I [](int i, T x) { i += 0; return x; }

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

struct monster{int l, r; long b;};

int main() {
    int n, m;
    cin >> n;
    long a[n+1];
    SegmentTree<long> sgt(n+1, "sum");
    for (int i=1; i<=n; i++) cin >> a[i];
    cin >> m;
    monster mons[m];
    for (auto &mi:mons) {
        cin >> mi.l >> mi.r >> mi.b;
        sgt.update(mi.l, sgt[mi.l]+mi.b);
    }
    sort(mons, mons+m, [](monster a, monster b) {
        return P{a.r, a.l} < P{b.r, b.l};
    });
    long dp[n+1];
    dp[0] = 0;
    int j=0;
    for (int i=1; i<=n; i++) {
        dp[i] = 0;
        for ( ; mons[j].r < i && j < m; j++)
            sgt.update(mons[j].l, sgt[mons[j].l]-mons[j].b);
        for (int k=0; k<i; k++)
            maximize(dp[i], max(sgt.query(k+1, i+1) - a[i], 0l) + dp[k]);
    }
    cout << *max_element(dp, dp+n+1) << '\n';
    return 0;
}