#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#include <cassert>
#include <initializer_list>

template <typename T>
class matrix {
    int h, w;
    vector<vector<T>> body;

    // 長方形の配列になっているかcheck
    bool check() {
        for (auto &b:body)
            if ((int)b.size() != w)
                return false;
        return true;
    }

public:
    matrix() = default;

    // 初期化子リスト matrix<T> mat{{0}, {1}, {2}}; みたいにかける
    matrix(initializer_list<initializer_list<T>> _body) {
        for (auto &bi:_body) body.emplace_back(vector<T>(bi.begin(), bi.end()));
        h = (int)body.size();
        w = (int)body[0].size();
        assert(check());
    }

    matrix(int _h, int _w, T init=0)
        : h(_h)
        , w(_w)
        , body((size_t)_h, vector<T>((size_t)_w, init)) {
    }
    // n x nの単位行列 matrix::I(n)でよべる
    static matrix I(int _n) {
        matrix m(_n, _n);
        for (size_t i=0; i<(size_t)_n; i++) m[i][i] = 1;
        return m;
    }

    pair<int, int> &shape() { return {h, w}; };
    
    template <typename ID> vector<T> &operator[](ID i) { return body[(size_t)i]; }
    template <typename ID> vector<T> operator[](ID i) const { return body[(size_t)i]; }

    auto begin() { return body.begin(); }
    auto end() { return body.end(); }
    auto begin() const { return body.begin(); }
    auto end() const { return body.end(); }

    matrix operator+(const matrix &r) {
        assert(h == r.h && w == r.w);
        matrix res(h, w);
        for (size_t i=0; i<(size_t)h; i++)
            for (size_t j=0; j<(size_t)w; j++)
                res[i][j] = body[i][j] + r[i][j];
        return res;
    }
    matrix operator-(const matrix &r) {
        assert(h == r.h && w == r.w);
        matrix res(h, w);
        for (size_t i=0; i<(size_t)h; i++)
            for (size_t j=0; j<(size_t)w; j++)
                res[i][j] = body[i][j] - r[i][j];
        return res;
    }
    matrix operator*(const matrix &r) {
        assert(w == r.h);
        matrix res(h, r.w);
        for (size_t i=0; i<(size_t)h; i++) {
            for (size_t j=0; j<(size_t)r.w; j++) {
                for (size_t k=0; k<(size_t)w; k++) {
                    res[i][j] += body[i][k] * r[k][j];
                }
            }
        }
        return res;
    }

    // TODO
    // T det() {
    //     assert(w == h);
        
    // }
    // matrix &inv() {
    //     matrix(h, w)
    // }

    // O(N^3 logk)
    matrix pow(const ll k) {
        assert(h == w);
        // if (k < 0) return matrix.inv().pow(-k);
        if (k <= 0) return matrix::I(h);
        else {
            matrix x = pow(k/2);
            if (k%2 == 0) return x * x;
            else return *this * x * x;
        }
    }
};

template <typename T>
ostream &operator<<(ostream &os, const matrix<T> &out) {
    for (auto &oi:out) {
        if (&oi != &*out.begin()) os << '\n';
        for (auto &oij:oi)
            if (&oij == &*oi.begin()) os << oij;
            else os << ' ' << oij;
    }
    return os;
}

template <typename T>
istream &operator>>(istream &is, matrix<T> &in) {
    for (auto &ini:in) {
        for (auto &inij:ini)
            is >> inij;
    }
    return is;
}

#include <cassert>
#define MAX 2000000  // 階乗をいくつまで計算するか

class modlong {
    long val;
    static long *invs, *facts, *finvs;

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
    static long MOD; // modの元

    // 初期化 値を引数に与えなかった場合はval=0としておく
    modlong(long init = 0) : val(init) {
        static bool call_once = initModlong(); // static変数の性質により一度だけ呼ばれる
        assert(call_once); // unusedの回避
        if (val < 0 || val >= MOD) val %= MOD;
        if (val < 0) val += MOD;   // 0以上であることを保証
    }

    // longへのキャスト operator long()で定義すると modlong +
    // longとかができなくなる
    inline long tol() { return this->val; }

    // 代入
    void operator=(const modlong &r) { this->val = r.val; }
    void operator=(const long &r) { *this = modlong(r); }

    // 足し算; 符号反転; 引き算
    modlong operator+(const modlong &r) {
        long ans = this->val + r.val;
        if (ans >= MOD) ans -= MOD;
        return modlong(ans);
    }
    modlong operator-() {
        long ans = MOD - this->val;
        return modlong(ans);
    }
    modlong operator-(const modlong &r) {
        modlong rr = r;
        return *this + (-rr);
    }

    //かけ算; 逆元; わり算
    modlong operator*(const modlong &r) {
        long ans = this->val * r.val;
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
        const long n = this->val, k = _k.val;
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;
        return modlong(facts[n]) * finvs[k] * finvs[n - k];
    }

    // 階乗
    modlong fact() { 
        assert(this->val <= MAX);
        return modlong(facts[this->val]);
    }

    friend bool operator<(const modlong &l, const modlong &r);
    friend bool operator>(const modlong &l, const modlong &r);
    friend bool operator==(const modlong &l, const modlong &r);
    friend bool operator!=(const modlong &l, const modlong &r);
    friend bool operator<=(const modlong &l, const modlong &r);
    friend bool operator>=(const modlong &l, const modlong &r);
    friend ostream &operator<<(ostream &os, const modlong &out);
    friend istream &operator>>(istream &is, modlong &out);
};

//比較
bool operator<(const modlong &l, const modlong &r) { return l.val < r.val; }
bool operator>(const modlong &l, const modlong &r) { return l.val > r.val; }
bool operator==(const modlong &l, const modlong &r) { return l.val == r.val; }
bool operator!=(const modlong &l, const modlong &r) { return !(l == r); }
bool operator<=(const modlong &l, const modlong &r) { return !(l > r); }
bool operator>=(const modlong &l, const modlong &r) { return !(l < r); }

// cout、cerr、cin用の演算子たち
ostream &operator<<(ostream &os, const modlong &out) {
    os << out.val;
    return os;
}
istream &operator>>(istream &is, modlong &in) {
    long inl;
    is >> inl;
    in.val = inl % modlong::MOD;
    return is;
}

// コンビネーション
inline modlong modComb(long n, long k) { return modlong(n).comb(k); }
// 階乗
inline modlong modFact(long n) { return modlong(n).fact(); }

// static変数たち
long *modlong::invs  = new long[MAX+1],
     *modlong::facts = new long[MAX+1],
     *modlong::finvs = new long[MAX+1];

long modlong::MOD = (long)1e9 + 7;

int main() {
    ll l, a, b;
    cin >> l >> a >> b >> modlong::MOD;
    ll i = 0, d = 1, s = a;
    matrix<modlong> mat{{d, 1, 0}, 
                        {0, 1, 1}, 
                        {0, 0, 1}},
                    vec{{0},
                        {a},
                        {b}};
    for (int k=1; k<=18; k++) {
        d *= 10;
        if (s > d) continue;
        mat[0][0] = d;
        ll prev = i;
        if (k < 18) i = min(i + (d - s - 1) / b + 1, l);
        else i = l;
        vec = mat.pow(i - prev) * vec;
        s += (i - prev) * b;
        if (i == l) break;
    }
    cout << vec[0][0] << endl;
    return 0;
}