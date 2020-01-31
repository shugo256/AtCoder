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
    int l[n];
    for (auto &li:l) cin >> li;
    sort(l, l+n);
    int ans=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            int k = lower_bound(l, l+n, l[i]+l[j]) - l;
            ans += max(k - i - 1, 0);
            //cerr << i << ' ' << j << ' ' << k << '\n';
        }
    }
    cout << ans << '\n';
    return 0;
}