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
    ll cnt[100010] = {0};
    ll sum = 0;
    for (int i=0, ai; i<n; i++) {
        cin >> ai;
        cnt[ai]++;
        sum += ai;
    }
    int q; cin >> q;
    for (int i=0, bi, ci; i<q; i++) {
        cin >> bi >> ci;
        sum += cnt[bi] * (ci - bi);
        cnt[ci] += cnt[bi];
        cnt[bi] = 0;
        cout << sum << '\n';
    }
    return 0;
}