#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    ll h;
    cin >> h;
    ll ans = 0, d = 1;;
    while (h > 0) {
        ans += d;
        h /= 2;
        d *= 2;
    }
    cout << ans << '\n';
    return 0;
}