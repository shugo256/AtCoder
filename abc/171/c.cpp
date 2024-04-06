#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    ll n;
    cin >> n;
    n--;
    ll d = 26;
    while (n >= d) {
        n -= d;
        d *= 26;
    }
    d /= 26;
    string ans;
    while (d > 0) {
        ans += 'a' + n / d;
        n %= d;
        d /= 26;
    }
    cout << ans << '\n';
    return 0;
}