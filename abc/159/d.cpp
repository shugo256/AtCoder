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
    ll cnt[n], a[n];
    fill(cnt, cnt+n, 0);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
    }
    ll sum = 0;
    for (auto &ci:cnt) sum += ci * (ci-1) / 2;
    for (auto &ai:a) {
        cout << sum - cnt[ai] + 1 << '\n';
    }
    return 0;
}