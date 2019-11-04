#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt[n];
    fill(cnt, cnt+n, 0);
    for (int i=0, a; i<n; i++) {
        cin >> a;
        cnt[a-1]++;
    }
    int rui[n+1];
    fill(rui, rui+n+1, 0);
    for (auto &ci:cnt)
        rui[ci]++;
    int prev = n;
    for (auto &ri:rui) {
        ri = prev - ri;
        prev = ri;
    }
    int lim[n+1], remain=n;
    lim[0] = n;
    for (int i=n; i>0; i--) {
        remain -= rui[i];
        lim[i] = remain / i;
        //cerr << i << ' ' << lim[i] << ' ' << rui[i] << ' ' << remain << '\n';
    }
    for (int i=1; i<=n; i++)
        cout << partition_point(lim, lim+n+1, [&] (int x) { return x >= i; }) - lim - 1 << '\n';
    return 0;
}