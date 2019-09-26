#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

long s(long n) {
    long res = 0;
    for ( ; n > 0; n /= 10) res += n % 10;
    return res;
}

int main() {
    int k;
    cin >> k;
    long n = 0, r = 1;
    for (int i=0; i<k; i++) {
        if ((n + r) >  s(n + r) * r) r *= 10;
        n += r;
        cout << n << '\n';
    }
    return 0;
}