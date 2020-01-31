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
    long cnt=0, prev = 0, best = 0;
    for (int i=0; i<n; i++) {
        long h; cin >> h;
        if (h > prev) cnt = 0;
        cnt++;
        prev = h;
        best = max(best, cnt);
    }
    cout << best - 1 << '\n';
    return 0;
}