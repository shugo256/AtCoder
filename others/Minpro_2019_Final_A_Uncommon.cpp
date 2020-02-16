#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>

using ll = long long;

using namespace std;

#include <map>
#include <cassert>

#define PRIME_MAX 100000

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

    auto begin() { return factors.begin(); }
    auto end()   { return factors.end();   }

    auto size()  { return factors.size(); }
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

int main() {
    int n, m;
    cin >> n >> m;
    int cnt[PRIME_MAX+1] = {}; 
    for (int i=0, ai; i<n; i++) {
        cin >> ai;
        for (int j=1; j*j<=ai; j++) {
            if (ai % j) continue;
            cnt[j]++;
            if (ai / j != j) cnt[ai/j]++;
        }
    }
    for (int i=1; i<=m; i++) {
        PrimeFactorization<int> pfi(i);
        int b = pfi.size(), ans = 0;
        for (int j=0; j<(1 << b); j++) {
            bitset<20> bsj(j);
            auto itr = pfi.begin();
            int fact = 1;
            for (int i=0; i<b; i++) {
                if (bsj[i])
                    fact *= itr->first;
                itr++;
            }
            if (bsj.count() % 2) ans -= cnt[fact];
            else ans += cnt[fact];
        }
        cout << ans << '\n';
    }
    return 0;
}