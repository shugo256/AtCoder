#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;

using namespace std;

int main() {
    long n;
    cin >> n;
    long r = (long)sqrt(n), ans = n;
    for (long i=1; i<=r; i++) {
        if (n % i != 0) continue;
        ans = min(ans, i - 1 + n / i - 1);
    }
    cout << ans << '\n';
    return 0;
}