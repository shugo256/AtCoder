#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;

using namespace std;

int main() {
    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        long a, b;
        cin >> a >> b;
        long r   = (long)sqrt(a * b),
             ans = r * 2;
        if (a != b) ans--;
        if (a * b <= r * r) ans--;
        if (a * b <= r * (r+1)) ans--;
        cout << ans << '\n';
    }
    return 0;
}