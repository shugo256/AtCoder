#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    long a[n+1], b[n];
    for (auto &ai:a) cin >> ai;
    for (auto &bi:b) cin >> bi;
    long sum = 0;
    for (int i=0; i<n; i++) {
        long mons = min(a[i], b[i]);
        sum += mons;
        b[i] -= mons;
        mons = min(a[i+1], b[i]);
        sum += mons;
        a[i+1] -= mons;
    }
    cout << sum << '\n';
    return 0;
}