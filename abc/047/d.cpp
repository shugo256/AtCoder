#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    int low = 1000000000, dif = 0, a[n], cnt = 1;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        low = min(low, a[i]);
        if (dif == a[i] - low) cnt++;
        else if (dif < a[i] - low) {
            dif = a[i] - low;
            cnt = 1;
        }
        // cerr << low << ' ' << dif << '\n';
    }
    cout << cnt << '\n';
    return 0;
}