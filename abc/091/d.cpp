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
    long ans = 0, a, b;
    int cnt[20] = {0};
    for (int i=0; i<n; i++) {
        cin >> a;
        ans += a * n;
        for (long j=0, d=1; j<20; (j++, d <<= 1)) 
            if (d & a) cnt[j]++;
    }
    for (int i=0; i<n; i++) {
        cin >> b;
        ans += b * n;
        for (long j=0, d=1; j<20; (j++, d <<= 1))
            if (d & b) ans -= d * cnt[j] * 2;
    }
    cout << ans << '\n';
    return 0;
}