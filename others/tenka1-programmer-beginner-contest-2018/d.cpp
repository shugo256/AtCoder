#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k=-1;
    cin >> n;
    int a = 1, b = 500;
    while (b - a > 1) {
        int c = (a + b) / 2;
        if (c * (c - 1) / 2 > n) b = c;
        else a = c;
    }
    if (n == a * (a - 1) / 2) {
        k = a;
        cout << "Yes" << '\n' << k << '\n';
    } else {
        cout << "No" << '\n';
        return 0;
    }
    for (int i=0; i<k; i++) {
        int l = k - 1, s = i + (i == 0);
        cout << l << ' ' << s;
        l--;
        if (i != 0) s += l;
        for ( ; l >= k-i && l > 0; l--) {
            cout << ' ' << s;
            s += l - 1;
        }

        for ( ; l > 0; l--) {
            s++;
            cout << ' ' << s;
        }
        cout << '\n';
    }
    return 0;
}