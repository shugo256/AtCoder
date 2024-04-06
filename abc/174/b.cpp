#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    ll d;
    cin >> n >> d;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        ll x, y; cin >> x >> y;
        if (x * x + y * y <= d * d) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}