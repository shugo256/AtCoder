#include <iostream>
#include <algorithm>
#include <vector>

#define MAXA 1100000
#define mod (long)(1e9+7)

using namespace std;

int main() {
    int n;
    cin >> n;
    int xors=0;
    long sums[MAXA], now[MAXA] = {0}; now[0] = 2;
    fill(sums, sums+MAXA, 1);
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        xors = xors^a;
        if (xors == 0) {
            for (int j=0; j<n; j++) {
                if (now[j] == 0 || sums[j] == 0) continue;
                sums[j] = (sums[j] * now[j]) % mod;
            }
            fill(now, now+MAXA, 0);
            now[0] = 2;
        } else {
            now[xors] += 1;
        }
    }
    if (xors != 0) sums[0] = 0;
    long ans=0;
    for (int i=0; i<MAXA; i++) {
        ans = (ans + sums[i]) % mod;
    }
    cout << ans << '\n';
    return 0;
}
