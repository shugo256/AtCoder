#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n], buf[n+1];
    for (auto &ai:a) cin >> ai;
    for (int i=0; i<k; i++) {
        fill(buf, buf+n, 0);
        for (int j=0; j<n; j++) {
            buf[max(0,   j-a[j])]++;
            buf[min(n, j+a[j]+1)]--;
        }
        int prev = 0;
        bool all_n = true;
        for (int j=0; j<n; j++) {
            a[j] = prev + buf[j];
            prev = a[j];
            if (a[j] < n) all_n = false;
        }
        if (all_n) break;
    }
    for (auto &ai:a) cout << ai << ' ';
    cout << '\n';
    return 0;
}