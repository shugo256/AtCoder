#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <cmath>

using ll = long long;

using namespace std;

int main() {
    int a, b, x;
    cin >> a >> b >> x;
    double ans;
    if (a * a * b >= 2 * x) {
        double side = (double)x * 2 / (a * b);
        ans = atan(b / side);
    } else {
        double up = (double)x * 2 / (a * a) - b;
        ans = atan((b - up) / a);
    }
    cout << setprecision(15) << ans * 180 / M_PI << '\n';
    return 0;
}