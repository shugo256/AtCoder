#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    long l;
    cin >> n >> l;
    long a, prev=-10000000000;
    int i = 0;
    for ( ; i<n; i++) {
        cin >> a;
        if (a + prev >= l) 
            break;
        prev = a;
    }
    if (i == n) {
        cout << "Impossible" << '\n';
        return 0;
    }
    cout << "Possible" << '\n';
    for (int j=1; j<i; j++) 
        cout << j << '\n';
    for (int j=n-1; j>i; j--) 
        cout << j << '\n';
    cout << i << '\n';
    return 0;
}