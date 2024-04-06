#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

#include <map>
#include <cassert>

using namespace std;

#define PRIME_MAX 200010

template <typename T>
class PrimeFactorization {
    static bool *isPrime;

    // isPrimeを初期化
    bool initPrimeFact() {
        fill(isPrime, isPrime+PRIME_MAX+1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= PRIME_MAX; i++)
            if (isPrime[i])
                for (int j = 2 * i; j <= PRIME_MAX; j += i) isPrime[j] = false;
        return true;
    }

    T pow(T x, int n) {
        if (n <= 0) return 1;
        else {
            T xn = pow(x, n/2);
            if (n%2 == 0) return xn*xn;
            else return xn*xn*x;
        }
    }

    map<T, int> factors;

public:
    PrimeFactorization(T x = 1) {
        static bool call_once = initPrimeFact();
        assert(call_once);
        for (ll i = 2; T(i * i) <= x; i++) {
            if (!isPrime[i]) continue;
            while (x % i == 0) {
                x /= (T)i;
                factors[(T)i]++;
            }
        }
        if(x > 1)
            factors[x] = 1;
    }

    PrimeFactorization(map<T, int> &facts) : factors(facts) {}

    void gcd(PrimeFactorization &r) {
        for (auto &f:r.factors)
            if (factors.count(f.first))
                factors[f.first] = min(factors[f.first], f.second);
    }
    void gcd(T rval) {
        auto r = PrimeFactorization(rval);
        gcd(r); 
    }

    void lcm(PrimeFactorization &r) {
        for (auto &f:r.factors)
            factors[f.first] = max(factors[f.first], f.second);
    }
    void lcm(T rval) {
        auto r = PrimeFactorization(rval);
        lcm(r); 
    }

    T val() {
        T ans = 1;
        for (auto &f:factors)
            ans *= pow(f.first, f.second);
        return ans;
    }

    int operator[](T x) {
        if (factors.count(x)) return factors[x];
        else return 0;
    }

    auto begin() { return factors.begin(); };
    auto end()   { return factors.end();   };
};

template <typename T>
PrimeFactorization<T> &pf_gcd(PrimeFactorization<T> &l, PrimeFactorization<T> &r) {
    PrimeFactorization<T> ans(l);
    ans.gcd(r);
    return ans;
}

template <typename T>
PrimeFactorization<T> &pf_lcm(PrimeFactorization<T> &l, PrimeFactorization<T> &r) {
    PrimeFactorization<T> ans(l);
    ans.lcm(r);
    return ans;
}

template <typename T>
bool *PrimeFactorization<T>::isPrime = new bool[PRIME_MAX+1];

#include <cassert>
#define MAX 400010  // 階乗をいくつまで計算するか

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

// べき乗
inline modlong modPow(ll n, ll k) { return modlong(n).pow(k); }
// コンビネーション
inline modlong modComb(ll n, ll k) { return modlong(n).comb(k); }
// 階乗
inline modlong modFact(ll n) { return modlong(n).fact(); }

// static変数たち c++17ならinlineでかけるのでclassの中に入れられる(https://ja.cppreference.com/w/cpp/language/static)
ll *modlong::invs  = new ll[MAX+1];
ll *modlong::facts = new ll[MAX+1];
ll *modlong::finvs = new ll[MAX+1];

ll modlong::MOD = 998244353ll;


int main() {
    int n, m;
    std::cin >> n >> m;

    modlong ans = 0;

    for (int i=1; i<=m; i++) {
        modlong pats = 1;
        PrimeFactorization<int> pf(i);

        for (auto &[key, val]:pf) {
            pats *= modComb(n + val - 1, val);
        }
        ans += pats;
    }
    std::cout << ans << '\n';
    return 0;
}