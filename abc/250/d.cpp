#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    std::vector<bool> isPrime(1000001, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= 1000000; i++)
        if (isPrime[i])
            for (int j = 2 * i; j <= 1000000; j += i) isPrime[j] = false;
    
    ll n;
    std::cin >> n;
    ll cnt = 0;
    for (ll p = 2; p * p * p * p <= n; p++) {
        if (!isPrime[p]) continue;
        for (ll q = p + 1; p * q * q * q <= n; q++) {
            if (isPrime[q]) cnt++;
        }
    }
    std::cout << cnt << '\n';
    return 0;
}