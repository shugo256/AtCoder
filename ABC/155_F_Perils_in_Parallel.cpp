#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>
#include <queue>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

using BS = bitset<100010>;

struct B {P p; BS ids;};

#include <functional>
#include <limits>

#define ASSIGN_I [](T &ival, T x) { ival = x; }  // i番目にxを代入(点更新のデフォルト)

template <typename T>
class SegmentTree {
    int n;                       // 葉の数
    T def;                 // 初期値 && 単位元
    vector<T> tree;              // 本体 

    using op_func_t = function<T(T, T)>;
    using up_func_t = function<void(T&, T)>;

    op_func_t op_func; // 区間クエリで使う処理
    up_func_t up_func; // 点更新で使う処理 ただの変更の他、i番目にxをたすみたいなこともできる

    // 区間[a, b)の総和(と言うか総operation(は？))
    // ノードk=[l, r)を見ている
    T _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def;            // 全く交差しない場合
        if (a <= l && r <= b) return tree[(size_t)k]; // 完全に包含される場合
        T vl = _query(a, b, k * 2 + 1, l, (l + r) / 2),
          vr = _query(a, b, k * 2 + 2, (l + r) / 2, r);
        return op_func(vl, vr);
    }

  public:
    SegmentTree(int _n, T _def, op_func_t _op_func, up_func_t _up_func = ASSIGN_I)
        : def(_def), op_func(_op_func), up_func(_up_func)  {
        n = 1;
        while (n < _n) n <<= 1;
        tree = vector<T>((size_t)(2*n - 1), def);
    }

    //よく使うやつら min, max, sum
    SegmentTree(int _n, T _def, string mode, up_func_t _up_func = ASSIGN_I)
        : SegmentTree(
            _n, 
            _def,
            mode == "max" ? [](T l, T r) { return max(l, r); } :
           (mode == "min" ? [](T l, T r) { return min(l, r); } :
                            [](T l, T r) { return l + r; }), // sum
            _up_func
        ) {}

    SegmentTree(int _n, string mode, up_func_t _up_func = ASSIGN_I)
        : SegmentTree(
            _n, 
            mode == "max" ? numeric_limits<T>::lowest() : 
           (mode == "min" ? numeric_limits<T>::max() :
                            0), // sum
            mode,
            _up_func
        ) {}

    template <typename ID>
    void update(ID i, T x) {
        i += (ID)n - 1;
        up_func(tree[(size_t)i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            tree[(size_t)i] = op_func(tree[(size_t)(i * 2 + 1)], tree[(size_t)(i * 2 + 2)]);
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

    auto begin() { return tree.begin() + n - 1; }
    auto end() { return tree.end(); }

    T operator[](int i) { return tree[ (size_t)(i + n - 1) ]; }
};
/*
コンストラクタ
SegmentTree(n, def, op_func, [up_func])
SegmentTree(n, def, mode, [up_func])
SegmentTree(n, mode, [up_func])
*/

int main() {
    int n, m;
    cin >> n >> m;
    P ab[n];
    for (auto &p:ab) {
        cin >> p.fi >> p.se;
    }
    sort(ab, ab+n);
    P bombs[m];
    for (auto &bi:bombs) {
        int l, r;
        cin >> l >> r;
        auto ppl = partition_point(ab, ab+n, [&](P x) { return x.fi < l; }),
             ppr = partition_point(ab, ab+n, [&](P x) { return x.fi <= r; });
        bi = {(int)(ppl - ab), (int)(ppr - ab)};
    }
    priority_queue<B, vector<B>, function<bool(B, B)>> pq([](B l, B r) {return l.p < r.p;});
    for (int i=0; i<n; i++) {
        B b;
        b.p = bombs[i];
        b.ids.set(i);
        pq.push(b);
    }
    B prev{P{-1, -1}, BS(0)};
    vector<B> seqs;
    while (!pq.empty()) {
        B f = pq.top(), org = f; pq.pop();
        if (f.p == prev.p) {
            continue;
        } else if (f.p.fi == prev.p.fi && f.p.se != prev.p.se) {
            f.p.fi = prev.p.se;
            f.ids ^= prev.ids;
            pq.push(f);
        } else {
            seqs.push_back(f);
            prev = f;
        }
    }
    int j = 0;
    BS ans;
    SegmentTree<
    for (int i=0; i<n; i++) {
        if (!ab[i].se) continue;
        while (seqs[j].p.fi < i) j++;
        if (seqs[j].p.fi != i) {
            cout << -1 << '\n';
            return 0;
        }
        ans ^= 
    }
    cout << n << '\n';
    return 0;
}