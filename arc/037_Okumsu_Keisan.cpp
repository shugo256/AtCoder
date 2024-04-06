#include <iostream>
#include <algorithm>
#include <queue>

#define INF 1000000000000000010

using namespace std;

int main() {
    long n, k;
    cin >> n >> k;
    long a[n], b[n];
    for (auto &ai:a) cin >> ai;
    for (auto &bi:b) cin >> bi;
    sort(b, b+n);
    long l = 0, r = INF, m = (l + r) / 2;
    while (l + 1 < r) {
        long cnt = 0;
        for (auto ai:a) {
            cnt += partition_point(b, b+n, [&](const long bj) {
                return ai * bj <= m;
            }) - b;
        }
        if (cnt < k)
            l = m;
        else
            r = m;
        m = (l + r) / 2;
    }
    cout << l + 1 << endl;
    return 0;
}