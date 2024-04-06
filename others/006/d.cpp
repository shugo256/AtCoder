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
    int a[2*n - 1]; for (auto &ai:a) cin >> ai;
    int l = 1, r = 2*n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        bool prev = (a[n-1] >= m);
        bool found = false;
        for (int i=1; i<n; i++) {
            bool left = (a[n-1-i] >= m), right = (a[n-1+i] >= m);
            if (left == prev || right == prev) {
                found = true;
                break;
            }
            prev = left;
        }
        if (prev) l = m;
        else r = m;
    }
    cout << l << '\n';
    return 0;
}