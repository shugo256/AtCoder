#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    ll a[4];
    for (auto &ai:a) cin >> ai;
    ll ans = a[0] * a[2];
    for (int i=0; i<2; i++) {
        for (int j=2; j<4; j++) {
            ans = max(ans, a[i] * a[j]);
        }
    }
    cout << ans << '\n';
    return 0;
}