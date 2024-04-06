#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long n;
    cin >> n;
    long sum=0, a[n];
    for (auto &ai:a) {
        cin >> ai;
        sum += ai;
    }
    long b = max(sum - n*(n-1), 0l), c = sum, k;
    for (k=b; k<=c; k++) {
        long step = 0;
        for (auto ai:a) {
            if ((ai + k) % (n + 1) == n) {
                step = -1;
                break;
            }
            if (ai + k >= n) 
                step += (ai + k - n) / (n + 1) + 1;
        }
        // cerr << k << ' ' << step << '\n';

        if (step == k) break;
    }
    cout << k << '\n';
    return 0;
}