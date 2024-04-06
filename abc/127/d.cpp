#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<long, size_t> P;

int main() {
    size_t n, m;
    cin >> n >> m;
    long a[n];
    for (auto &ai:a) cin >> ai;
    P cb[m];
    for (auto &cbj : cb) cin >> cbj.second >> cbj.first;
    sort(a, a + n);
    sort(cb, cb + m, greater<P>());

    // for (auto &ai : a) cerr << ai << '\n';
    // for (auto &cbj : cb) cerr << cbj.first << ' ' << cbj.second << '\n';
    size_t j = 0, remain=0;
    long sum = 0;
    for (size_t i = 0; i < n; i++) {
        if (remain == 0) {
            if (i > 0) j++;
            remain = cb[j].second;
        }
        if (j == m || cb[j].first <= a[i]) {
            sum += a[i];
            continue;
        }
        sum += cb[j].first;
        remain--;
    }
    cout << sum << '\n';
    return 0;
}
