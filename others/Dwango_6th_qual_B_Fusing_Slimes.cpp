#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

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

#include <cassert>
#define MAX 2000000  // 階乗をいくつまで計算するか

class modlong {
    ll val;
    static ll *invs, *facts, *finvs;

    // 階乗, 逆元, 階乗の逆元をMAXまで求める
    bool initModlong() {
        invs[1] = 
        facts[0] = facts[1] =
        finvs[0] = finvs[1] = 1;
        for (int i=2; i<=MAX; i++) {
            invs[i]  = -invs[MOD % i] * (MOD / i) % MOD;
            facts[i] = facts[i - 1] * i % MOD;
            finvs[i] = finvs[i - 1] * invs[i] % MOD;
        }
        return true;
    }

public:
    static ll MOD; // modの元

    // 初期化 値を引数に与えなかった場合はval=0としておく
    modlong(ll init = 0) : val(init) {
        static bool call_once = initModlong(); // static変数の性質により一度だけ呼ばれる
        assert(call_once); // unusedの回避
        if (val < 0 || val >= MOD) val %= MOD;
        if (val < 0) val += MOD;   // 0以上であることを保証
    }

    // llへのキャスト operator ll()で定義すると modlong +
    // llとかができなくなる
    inline ll toll() { return this->val; }

    // 代入
    void operator=(const modlong &r) { this->val = r.val; }
    void operator=(const ll &r) { *this = modlong(r); }

    // 足し算; 符号反転; 引き算
    modlong operator+(const modlong &r) {
        ll ans = this->val + r.val;
        if (ans >= MOD) ans -= MOD;
        return modlong(ans);
    }
    modlong operator-() {
        ll ans = MOD - this->val;
        return modlong(ans);
    }
    modlong operator-(const modlong &r) {
        modlong rr = r;
        return *this + (-rr);
    }

    //かけ算; 逆元; わり算
    modlong operator*(const modlong &r) {
        ll ans = this->val * r.val;
        return modlong(ans);
    }
    modlong inv() {
        assert(*this != 0);
        if (*this == 1) return modlong(1);

        modlong p, q = *this, m(0), n(1), r, c;
        p.val = MOD;  // p=modとかくとp.val=mod%mod=0となってしまう
        while (q > MAX) {
            r = p.val % q.val;  // r.val=p.val % q.val
                                // とかくよりもこのほうが代入時に%modされるので安全
            c = m.val - n.val * (p.val / q.val);
            p = q, q = r, m = n, n = c;
        }
        return n * invs[q.val];
    }
    modlong operator/(const modlong &r) { return *this * modlong(r).inv(); }
    modlong operator%(const modlong &r) { return modlong(this->val % r.val); }

    // ++ -- 前付きと後ろ付き
    void operator++() { ++this->val; }
    void operator++(int a) {
        a = 0;
        this->val++;
    }  // a使ってなくねっていうwarningをsilenceするためにaをいじってる
    void operator--() { --this->val; }
    void operator--(int a) {
        a = 0;
        this->val--;
    }

    // 四則演算&代入
    void operator+=(const modlong &r) { *this = *this + r; }
    void operator-=(const modlong &r) { *this = *this - r; }
    void operator*=(const modlong &r) { *this = *this * r; }
    void operator/=(const modlong &r) { *this = *this / r; }
    void operator%=(const modlong &r) { *this = *this % r; }

    // べき乗
    modlong pow(long n) {
        if (n < 0)
            return inv().pow(-n);  // 逆元の-n乗
        else if (n == 0)
            return modlong(1);

        modlong half = pow(n / 2);
        if (n % 2)
            return *this * half * half;
        else
            return half * half;
    }
    modlong pow(modlong n) { return pow(n.val); }

    // コンビネーション
    modlong comb(modlong _k) {
        assert(this->val <= MAX);
        const ll n = this->val, k = _k.val;
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;
        return modlong(facts[n]) * finvs[k] * finvs[n - k];
    }

    // 階乗
    modlong fact() { 
        assert(this->val <= MAX);
        return modlong(facts[this->val]);
    }

    friend bool operator<(const modlong &l, const modlong &r) { return l.val < r.val; }
    friend bool operator>(const modlong &l, const modlong &r) { return l.val > r.val; }
    friend bool operator==(const modlong &l, const modlong &r) { return l.val == r.val; }
    friend bool operator!=(const modlong &l, const modlong &r) { return !(l == r); }
    friend bool operator<=(const modlong &l, const modlong &r) { return !(l > r); }
    friend bool operator>=(const modlong &l, const modlong &r) { return !(l < r); }

    friend ostream &operator<<(ostream &os, const modlong &out) {
        os << out.val;
        return os;
    }
    friend istream &operator>>(istream &is, modlong &in) {
        ll inl;
        is >> inl;
        in.val = inl % modlong::MOD;
        return is;
    }
};

// コンビネーション
inline modlong modComb(ll n, ll k) { return modlong(n).comb(k); }
// 階乗
inline modlong modFact(ll n) { return modlong(n).fact(); }

// static変数たち c++17ならinlineでかけるのでclassの中に入れられる(https://ja.cppreference.com/w/cpp/language/static)
ll *modlong::invs  = new ll[MAX+1];
ll *modlong::facts = new ll[MAX+1];
ll *modlong::finvs = new ll[MAX+1];

ll modlong::MOD = (ll)1e9 + 7;


int main() {
    int n;
    cin >> n;
    SegmentTree<modlong> x(n, "sum");
    for (int i=0; i<n; i++) {
        modlong xi; cin >> xi;
        x.update(i, xi);
    };
    modlong ans = 0;
    for (int i=1; i<n-1; i++)
        ans += (x.query(i, n-1) - x.query(0, n-1-i)) * modFact(i-1) * modFact(n-i-2) * modComb(n-1, i+1);
    for (int i=0; i<n-1; i++)
        ans += (x[n-1] - x[i]) * modFact(i) * modFact(n-i-2) * modComb(n-1, n-1-i);
    cout << ans << '\n';
    return 0;
}