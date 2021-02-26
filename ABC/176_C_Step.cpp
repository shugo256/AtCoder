#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    ll ans = 0, prev = 0;
    for (int i=0; i<n; i++) {
        ll ai; cin >> ai;
        ans += max(ai, prev) - ai;
        prev = max(ai, prev);
    }
    cout << ans << '\n';
    return 0;
}