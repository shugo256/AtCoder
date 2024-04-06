#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int cnt[n];
    fill(cnt, cnt+n, 0);
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int d = min(j - i, abs(j-y) + 1 + abs(i-x));
            cnt[d]++;
        }
    }
    for (int k=1; k<n; k++) cout << cnt[k] << '\n';
    return 0;
}