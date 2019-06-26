#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int c = (n-1) * (n-2) / 2;
    if (k > c) {
        cout << -1 << '\n';
        return 0;
    } 
    int m = n - 1 + (c - k);
    cout << m << '\n';
    for (int i=2; i<=n; i++)
        cout << 1 << ' ' << i << '\n';
    m -= n-1;
    for (int i=2; i<=n; i++) {
        for (int j=2; j<i; j++) {
            if (m == 0) break;
            cout << j << ' ' << i << '\n';
            m--;
        }
        if (m == 0) break;
    }
    return 0;
}
