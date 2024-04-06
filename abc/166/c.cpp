#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int total[n], less[n];
    int h[n];
    for (auto &hi:h) cin >> hi;
    fill(total, total+n, 0);
    fill(less, less+n, 0);
    for (int i=0, ai, bi; i<m; i++) {
        cin >> ai >> bi;
        ai --; bi--;
        total[ai]++; total[bi]++;
        if (h[ai] > h[bi]) {
            less[ai]++;
        }
        if (h[ai] < h[bi]) {
            less[bi]++;
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (less[i] == total[i]) ans++;
    }
    cout << ans << '\n';
    return 0;
}