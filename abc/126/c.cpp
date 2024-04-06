#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    double sum = max(0.0, 1 - (double)(k - 1) / n), flip = 1.0;
    int prev = k;
    while (k != prev || k != 1) {
        k = (k + 1) / 2;
        flip /= 2.0;
        //cerr << ' ' <<  k << prev << ' ' << flip << ' ' << sum << '\n';
        if (n >= k) {
            sum += ((double)(min(prev,n+1) - k) / (double)n) * flip;
        }
        prev = k;
    }
    cout << setprecision(15) << sum << '\n';
    return 0;
}
