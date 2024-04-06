#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

int main() {
    long n, k;
    cin >> n >> k;
    long rui[n+1];
    rui[0] = 0;
    for (int i=0; i<n; i++) {
        long ai; cin >> ai;
        rui[i+1] = (rui[i] + ai) % k;
    }
    map<long, long> acnt;
    long ans=0;
    for (long i=0; i<=n; i++) {
        if (i >= k) acnt[(i + k - rui[i-k]) % k]--;
        long r = (i + k - rui[i]) % k;
        ans += acnt[r];
        // cerr << i << ' ' << rui[i] << ' ' << r << ' ' << acnt[r] << '\n';
        acnt[r]++;
    }
    cout << ans << '\n';
    return 0;
}