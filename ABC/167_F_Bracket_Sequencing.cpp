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

#include <functional>
#include <limits>
#include <unordered_map>

#define ASSIGN_I [](elem_t &ival, elem_t x) { ival = x; }  // i番目にxを代入(点更新のデフォルト)

template <
    typename elem_t, 
    typename op_func_t = function<elem_t(elem_t, elem_t)>, 
    typename up_func_t = function<void(elem_t&, elem_t)>
>
class SegmentTree {
    size_t n;            // 葉の数(指定した要素数以上で最小の2べき)
    const elem_t def;    // 初期値 && 単位元
    vector<elem_t> tree; // 本体 

    op_func_t op_func;   // 区間クエリで使う処理
    up_func_t up_func;   // 点更新で使う処理 ただの変更の他、i番目にxをたすみたいなこともできる

    // stringでモード指定できるように
    // TODO: Change here to 'inline static' as soon as C++17 become available in AtCoder (and AOJ).
    //       I personally don't like initializing static vars outside.
    static unordered_map<string, elem_t> def_map;
    static unordered_map<string, op_func_t> oper_map;

  public:
    SegmentTree(int _n, elem_t _def, op_func_t _op_func, up_func_t _up_func = ASSIGN_I)
        : def(_def), op_func(_op_func), up_func(_up_func)  {
        n = 1;
        while (n < (size_t)_n) n <<= 1;
        tree = vector<elem_t>(n*2, def);
    }

    SegmentTree(int _n, elem_t _def, string mode, up_func_t _up_func = ASSIGN_I)
        : SegmentTree(_n, _def, oper_map[mode], _up_func) {}

    SegmentTree(int _n, string mode, up_func_t _up_func = ASSIGN_I)
        : SegmentTree(_n, def_map[mode], oper_map[mode], _up_func) {}

    inline void update(int _i, elem_t x) {
        size_t i = (size_t)_i;
        i += n;
        up_func(tree[i], x);
        while (i /= 2) {
            tree[i] = op_func(tree[(i * 2)], tree[(i * 2 + 1)]);
        }
    }

    // 区間[l, r)の総和(と言うか総operation(は？))
    inline elem_t query(int _l, int _r) {
        size_t l = (size_t)_l, r = (size_t)_r;
        elem_t res_l = def, res_r = def;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res_l = op_func(res_l, tree[l++]);
            if (r & 1) res_r = op_func(tree[--r], res_r);
        }
        return op_func(res_l, res_r);
    }

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

    auto begin() { return tree.begin() + n; }
    auto end() { return tree.end(); }

    elem_t operator[](int i) { return tree[ (size_t)(i + n) ]; }
};

template<typename elem_t, typename op_func_t, typename up_func_t> 
unordered_map<string, elem_t> SegmentTree<elem_t, op_func_t, up_func_t>::def_map{
    {"max", numeric_limits<elem_t>::lowest()},
    {"min", numeric_limits<elem_t>::max()},
    {"sum", static_cast<elem_t>(0)}
};

template<typename elem_t, typename op_func_t, typename up_func_t> 
unordered_map<string, op_func_t> SegmentTree<elem_t, op_func_t, up_func_t>::oper_map{
    {"max", [](elem_t l, elem_t r) { return max(l, r); }},
    {"min", [](elem_t l, elem_t r) { return min(l, r); }},
    {"sum", [](elem_t l, elem_t r) { return l + r; }}
};
/*
コンストラクタ
SegmentTree(n, def, op_func, [up_func])
SegmentTree(n, def, mode, [up_func])
SegmentTree(n, mode, [up_func])
*/


P check_lr(string &s) {
    int n = s.size();
    P ans;
    int left = 0, right = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '(') left++;
        if (s[i] == ')' && right < left) right++;
    }
    ans.se = left - right;
    left = 0, right = 0;
    for (int i=n-1; i>=0; i--) {
        if (s[i] == ')') right++;
        if (s[i] == '(' && left < right) left++;
    }
    ans.fi = right - left;
    return ans;
}

struct retu {
    int l, r, i;
};

#define INF 10000000

int main() {
    int n;
    cin >> n;
    vector<P> lrs;
    P left_edge = {0, 0}, right_edge = {0, 0};
    int dif = 0, complete = 0;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        P lr = check_lr(s);
        lrs.push_back(lr);
        if (lr.fi == 0 && lr.se == 0) {
            complete++;
            continue;
        }
        if (lr.fi == 0 && (left_edge != P{0, 0} || left_edge.se < lr.se)) {
            left_edge = lr;
        }
        if (lr.se == 0 && (right_edge != P{0, 0} || right_edge.fi < lr.fi))
            right_edge = lr;
        dif += lr.fi - lr.se;
    }
    if (complete < n && (left_edge == P{0, 0} || right_edge == P{0, 0} || dif != 0)) {
        cout << "No" << '\n';
        return 0;
    }
    vector<P> sorter;
    int cur = left_edge.se;
    for (auto &lri:lrs) {
        if (lri == left_edge) {
            left_edge = {-1, -1};
        } else if (lri == right_edge) {
            right_edge = {-1, -1};
        } else {
            sorter.push_back(lri);
        }
    }
    sort(sorter.begin(), sorter.end());
    SegmentTree<retu> sgt(n-2, retu{INF, 0, -1}, [](retu a, retu b) {
        if (a.r - a.l > b.r - b.l)
            return a;
        else return b;
    });
    for (int i=0; i<n-2; i++) {
        sgt.update(i, {sorter[i].fi, sorter[i].se, i});
    }
    for (int i=0; i<n-2; i++) {
        int end = partition_point(sorter.begin(), sorter.end(), [&](P a) {
            return a.fi <= cur;
        }) - sorter.begin();
        retu x = sgt.query(0, end);
        cur += x.r - x.l;
        if (x.i < 0 || cur < 0) {
            cout << "No" << '\n';
            return 0;
        }
        sgt.update(x.i, retu{INF, 0, -1});
    }
    cout << "Yes" << '\n';
    return 0;
}