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
    ll a[n], b[n];
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a, a+n);
    sort(b, b+n, greater<int>());
    if (n % 2) {
        cout << b[n/2] - a[n/2] + 1 << '\n';
    } else {
        cout << (b[n/2] + b[(n-1)/2]) - (a[n/2] + a[(n-1)/2]) + 1 << '\n';
    }
    return 0;
}