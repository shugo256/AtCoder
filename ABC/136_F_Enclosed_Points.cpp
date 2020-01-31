#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>
#include <numeric>

using namespace std;

#include <iostream>

using namespace std;

///////     longをmodの計算をするように拡張

#define MOD (long)(998244353)
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

using B = bitset<200000>;

int main() {
    int n;
    cin >> n;
    long x[n], y[n];
    for (int i=0; i<n; i++) cin >> x[i] >> y[i];
    vector<size_t> xi(n), yi(n);
    iota(xi.begin(), xi.end(), 0);
    iota(yi.begin(), yi.end(), 0);
    sort(xi.begin(), xi.end(), [&](size_t l, size_t r) {
        return x[l] < x[r];
    });
    sort(yi.begin(), yi.end(), [&](size_t l, size_t r) {
        return y[l] < y[r];
    });
    B xrui[n+1], yrui[n+1];
    xrui[0].reset(); yrui[0].reset();
    for (size_t i=0; i<n; i++) {
        xrui[i+1].set(xi[i]);
        yrui[i+1].set(yi[i]);
    }
    int xinv[n], yinv[n];
    for (int i=0; i<n; i++)
        xinv[xi[i]] = yinv[yi[i]] = i;
    modlong sum = 0;
    for (int i=0; i<n; i++) {
        sum += (xrui[xinv] & yrui[yinv]).count
    }
    cout << n << '\n';
    return 0;
}