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

#define PRIME_MAX 100010

using namespace std;

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
    auto size() { return factors.size(); }
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
    int n;
    std::cin >> n;
    std::cout << 1;
    std::vector<int> ans(n+1, 0);
    ans[1] = 1;
    for (int i=2; i<=n; i++) {
        int best = 1;
        auto pf = PrimeFactorization<int>(i);
        for (auto &[key, val]:pf) {
            amax(ans[i], ans[i / key] + 1);
        }
        std::cout << ' ' << ans[i];
    }
    std::cout << '\n';
    return 0;
}