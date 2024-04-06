#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <numeric>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        ll n, s, k;
        std::cin >> n >> s >> k;
        ll x, y;
        ll gcd = extGCD(n, k, x, y);
        if (s % gcd != 0) {
            std::cout << -1 << '\n';
            continue;
        }
        x *= s / gcd;
        y *= s / gcd;
        if (x <= 0) {
            ll num = (-x) / k + 1;
            x += num * k;
            y -= num * n;
        }
        ll slide = std::min(x / (k / gcd), (-y) / (n / gcd));
        x -= slide * (k / gcd);
        y += slide * (n / gcd);
        // std::cerr << x << ' ' << y << std::endl;
        std::cout << -y << '\n';
    }
    return 0;
}