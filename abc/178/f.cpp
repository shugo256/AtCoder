#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    int as = 0, bs = 0;
    set<int> difs;
    for (auto &ai:a) cin >> ai;
    for (auto &bi:b) cin >> bi;
    for (int i=0; i<n; i++) difs.insert(i);
    for (int i=1; i<=n; i++) {
        int ae = upper_bound(a, a+n, i) - a;
        int be = upper_bound(b, b+n, i) - b;
        if (ae > as && be > bs) {
            int start = as - (be-1);
            int goal  = (ae-1) - bs;
            if (start + n <= goal) {
                difs.erase(difs.begin(), difs.end());
            } else {
                start = (start + n) % n;
                goal  = (goal  + n) % n;
                if (start <= goal) {
                    auto s_itr = difs.lower_bound((start + n) % n);
                    auto g_itr = difs.upper_bound((goal  + n) % n);
                    difs.erase(s_itr, g_itr);
                } else {
                    auto s_itr = difs.lower_bound((start + n) % n);
                    difs.erase(s_itr, difs.end());
                    auto g_itr = difs.upper_bound((goal  + n) % n);
                    difs.erase(difs.begin(), g_itr);
                }
            }
        }
        as = ae;
        bs = be;
    }
    if (difs.size() == 0) {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
        int d = *difs.begin();
        for (int i=0; i<n; i++) {
            cout << b[(i-d + n) % n] << (i < n-1 ? ' ' : '\n');
        }
    }
    return 0;
}