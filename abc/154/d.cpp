#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using ll = long long;

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int p[n];
    for (auto &pi:p) {
        cin >> pi;
        pi += 1;
    }
    int i=0, sum=0;
    for ( ; i<k; i++) sum += p[i];
    int ans2 = sum;
    for ( ; i<n; i++) {
        sum += p[i] - p[i-k];
        ans2 = max(ans2, sum);
    }
    cout << setprecision(15) << (double)ans2 / 2. << '\n';
    return 0;
}