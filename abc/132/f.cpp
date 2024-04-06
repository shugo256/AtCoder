#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;

using namespace std;

#define MOD (long)(1e9 + 7)
#define MAX 1000000  // 階乗をいくつまで計算するか

class modlong;
void computeAll(long n);
modlong modComb(long n, long k);
modlong modFact(long n);

class modlong {
    long val;
    const long mod = MOD;

public:
    // 初期化 値を引数に与えなかった場合はval=0としておく
    modlong(long init = 0) {
        while (init < 0) init += mod;  // 0以上であることを保証
        val = init % mod;
    }

    // longへのキャスト operator long()で定義すると modlong +
    // longとかができなくなる
    long tol() { return this->val; }

    // 代入
    void operator=(const modlong &r) { this->val = r.val; }
    void operator=(const long &r) {
        long rr = r;
        while (rr < 0) rr += mod;  // 0以上であることを保証
        this->val = rr % mod;
    }

    //比較
    bool operator<(const modlong &r) { return this->val < r.val; }
    bool operator>(const modlong &r) { return this->val > r.val; }
    bool operator==(const modlong &r) { return this->val == r.val; }
    bool operator!=(const modlong &r) { return !(*this == r); }
    bool operator<=(const modlong &r) { return !(*this > r); }
    bool operator>=(const modlong &r) { return !(*this < r); }

    // 足し算; 符号反転; 引き算
    modlong operator+(const modlong &r) {
        long aval = (this->val + r.val) % mod;
        modlong ans(aval);
        return ans;
    }
    modlong operator-() {
        long aval = (mod - this->val) % mod;
        modlong ans(aval);
        return ans;
    }
    modlong operator-(const modlong &r) {
        modlong rr = r;
        return *this + (-rr);
    }

    //かけ算; 逆元; わり算
    modlong operator*(const modlong &r) {
        long aval = (this->val * r.val) % mod;
        modlong ans(aval);
        return ans;
    }
    modlong inv() {
        if (*this == 1) return modlong(1);
        if (*this == 0) cerr << "modlong warning: dividebyzero!!!" << '\n';

        modlong p, q = *this, m(0), n(1), r, c;
        p.val = mod;  // p=modとかくとp.val=mod%mod=0となってしまう
        while (q > 1) {
            r = p.val %
                q.val;  // r.val=p.val / q.val
                        // とかくよりもこのほうが代入時に%modされるので安全
            c = m.val - n.val * (p.val / q.val);
            p = q, q = r, m = n, n = c;
        }
        return n;
    }
    modlong operator/(const modlong &r) {
        modlong rr = r;
        return *this * rr.inv();
    }

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

    // コンビネーション modCombは少し下に書いてある
    modlong C(modlong k) { return modComb(this->val, k.val); }
    modlong fact() { return modFact(this->val); }

    friend ostream &operator<<(ostream &os, const modlong &out);
    friend istream &operator>>(istream &is, modlong &out);
};

// cout、cerr、cin用の演算子たち
ostream &operator<<(ostream &os, const modlong &out) {
    os << out.val;
    return os;
}
istream &operator>>(istream &is, modlong &in) {
    long inl;
    is >> inl;
    in.val = inl % MOD;
    return is;
}

//////      階乗を全て求める -> 二項係数を求める

long invs[MAX], facts[MAX], finvs[MAX];
long listlen = 0;  // invs, facts, finvsの配列長
void computeAll(long n) {
    if (n >= MAX)
        cerr << "modlong error: index out of range in computeAll" << '\n';
    long i;
    if (listlen == 0) {
        invs[1] = 1;
        facts[0] = 1;
        facts[1] = 1;
        finvs[0] = 1;
        finvs[1] = 1;
        i = 2;
    } else {
        i = listlen;
    }
    if (n < 2) return;
    for (; i <= n; i++) {
        invs[i] = -invs[MOD % i] * (MOD / i) % MOD;
        facts[i] = facts[i - 1] * i % MOD;
        finvs[i] = finvs[i - 1] * invs[i] % MOD;
    }
    listlen = n + 1;  // 次呼び出すときはn+1以降から再開すれば良い
}
// コンビネーション
modlong modComb(long n, long k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (listlen <= n) computeAll(n);  // 毎回足りない分だけ補う
    return modlong(facts[n]) * finvs[k] * finvs[n - k];
}
// 階乗
modlong modFact(long n) {
    if (listlen <= n) computeAll(n);  // 毎回足りない分だけ補う
    return modlong(facts[n]);
}

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
    long n, k;
    cin >> n >> k;
    long r = (int) sqrt(n);
    vector<BIT<modlong>> dp_bit(k+1, BIT<modlong>(r)), dp_inv(k+1, BIT<modlong>(r));
    dp_bit[0].add(0, 1);
    long inv_cnt[r], prev = r;
    for (long i=0; i<r; i++) {
        inv_cnt[i] = n / (r - i) - prev;
        prev = n / (r - i);
    }
    for (long i=0; i<k; i++) {
        for (int j=0; j<r; j++) {
            dp_bit[i+1].add(j, dp_bit[i].sum() + dp_inv[i].sum(r - j));
            dp_inv[i+1].add(j, dp_bit[i].sum(r - j) * inv_cnt[j]);
        }
    }
    cout << dp_bit[k].sum() + dp_inv[k].sum() << '\n';
    return 0;
}