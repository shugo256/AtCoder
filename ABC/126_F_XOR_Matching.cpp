#include <iostream>
#include <algorithm>

using namespace std;

int powi(int x, int a) {
    if (a == 0) return 1;
    else {
        int xa = powi(x, a/2);
        if (a%2 == 0) return xa*xa;
        else return xa*xa*x;
    }
}

int main() {
    int m, k;
    cin >> m >> k;
    int len = powi(2, m);
    if (k >= len) {
        cout << -1 << '\n';
        return 0;
    }
    if (m == 1) {
        if (k == 0) cout << "0 0 1 1\n";
        else cout << -1 << '\n';
        return 0;
    }
    for (int j=0; j<len; j++)
        if (j != k)
            cout << j << ' ';
    cout << k << ' ';
    for (int j=len-1; j>=0; j--)
        if (j != k)
            cout << j << ' ';
    cout << k << '\n';
    return 0;
}
