#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;

using namespace std;

int main() {
    long t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    long d1 = t1 * (a1 - b1),
         d2 = t2 * (a2 - b2);
    if (d1 == 0 || d1 + d2 == 0) {
        cout << "infinity\n";
        return 0;
    }
    long ab1 = abs(d1),
         ab2 = abs(d1 + d2);
    if (d1 / ab1 == (d1 + d2) / ab2) {
        cout << 0 << '\n';
        return 0;
    }
    cout << 2 * (ab1 / ab2) + (ab1 % ab2 > 0) << '\n';
    return 0;
}