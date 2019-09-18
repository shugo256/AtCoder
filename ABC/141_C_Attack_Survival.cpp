#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    long n, k, q;
    cin >> n >> k >> q;
    long p[n];
    fill(p, p+n, k - q);
    for (long i=0; i<q; i++) {
        int a; cin >> a;
        p[a-1]++;
    }
    for (auto &pi:p)
        cout << (pi > 0 ? "Yes" : "No") << '\n';
    return 0;
}