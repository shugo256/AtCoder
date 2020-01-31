#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

int main() {
    long n;
    cin >> n;
    long p[n], pinv[n];
    for (long i=0; i<n; i++) {
        cin >> p[i];
        p[i]--;
        pinv[p[i]] = i;
    }
    set<long> used;
    used.insert(-1);
    used.insert(n);
    used.insert(pinv[n-1]);
    long ans = 0;
    for (long i=n-2; i>=0; i--) {
        auto itr = used.lower_bound(pinv[i]),
             r1 = itr,
             l1 = (--itr),
             r2 = r1,
             l2 = l1;
        if (*r1 < n) {
            r2++;
            ans += (i+1) * (*r2 - *r1) * (pinv[i] - *l1);
        }
        if (*l1 >= 0) {
            l2--;
            ans += (i+1) * (*r1 - pinv[i]) * (*l1 - *l2);
        }
        used.insert(pinv[i]);
    }
    cout << ans << '\n';
    return 0;
}