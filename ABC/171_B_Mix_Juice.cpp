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
    int p[n]; for (auto &pi:p) cin >> pi;
    sort(p, p+n);
    int ans = 0; for (int i=0; i<k; i++) ans += p[i];
    cout << ans << '\n';
    return 0;
}