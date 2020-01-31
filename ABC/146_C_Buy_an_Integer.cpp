#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    long a, b, x;
    cin >> a >> b >> x;
    long ans = 0, up=10;
    for (long d=1; d<=10; (d++, up*=10)) {
        long left = x - d * b,
             n = left / a;
        if (up <= n) n = up - 1;
        if (up / 10 <= n) {
            ans = (d < 10 ? n : 1000000000);
        }
        else break;
        // cerr << d << ' ' << up << ' ' << n << '\n';
    }
    cout << ans << '\n';
    return 0;
}