#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    if (n == x) {
        cout << "Yes" << '\n';
        for (int i=1; i<2*n; i++) cout << i << '\n';
    } else if (1 < x && x < 2*n - 1) {
        cout << "Yes" << '\n';
        int i=2;
        for ( ; i<n; i++) 
            cout << i + (i >= x) << '\n';
        cout << 1 << '\n' 
             << x << '\n'
             << 2*n - 1 << '\n';
        for ( ; i+2<2*n; i++) 
            cout << i + (i >= x) << '\n';
    } else
        cout << "No" << '\n';
    return 0;
}