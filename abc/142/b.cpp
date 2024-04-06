#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i=0, h; i<n; i++) {
        cin >> h;
        if (h >= k) ans++;
    }
    cout << ans << '\n';
    return 0;
}
