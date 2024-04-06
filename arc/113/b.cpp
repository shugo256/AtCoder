#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

ll modPow(ll n, ll k, ll m) {
    if (k == 0) return 1 % m;
    else {
        ll half = modPow(n, k / 2, m);
        return (half * half % m) * (k % 2 ? n : 1) % m;
    }
}


int main() {
    ll a, b, c;
    std::cin >> a >> b >> c;
    ll d = a % 10;

    std::vector lapA(1, 1);
    std::vector usedA(10, -1);
    usedA[1] = 0;
    int offA;
    for (int i = 1; ; i++) {
        if (usedA[(lapA.back() * d) % 10] >= 0) {
            offA = usedA[(lapA.back() * d) % 10];
            break;
        }
        lapA.push_back((lapA.back() * d) % 10);
        usedA[lapA.back()] = i;
    }

    int n = lapA.size() - offA;
    // std::cerr << lapA.size() << ' ' << offA << std::endl;
    if (b == 1) {
        std::cout << (n > 1 ? lapA[1] : 1) << '\n';
    } else {
        ll pow = 1;
        bool bigger = false;
        for (int i=0; i<c; i++) {
            if (pow > offA / b) {
                bigger = true;
                break;
            }
            else pow *= b;
        }
        if (bigger) {
            std::cout << lapA[(modPow(b, c, n) - offA + n * offA) % n + offA] << '\n';
        } else {
            std::cout << lapA[pow] << '\n';
        }
    }
    return 0;
}