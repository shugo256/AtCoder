#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using ull = unsigned long long;

using namespace std;


int main() {
    ull n;
    double p;
    cin >> p >> n;
    double doubling = p, ans = 0;
    for (int i=0; i<64; i++) {
        if ((n >> i) & 1) {
            ans = doubling * (1 - ans) + (1 - doubling) * ans;
        }
        doubling = doubling * (1-doubling) * 2;
    }
    cout << setprecision(15) << fixed << ans << '\n';
    return 0;
}