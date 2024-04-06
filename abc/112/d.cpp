#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= m / n; i++) {
        if (m % i == 0) {
            ans = i;
            if (i >= n) {
                ans = m / ans;
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}