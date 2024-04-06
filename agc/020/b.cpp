#include <iostream>

using namespace std;

int main() {
    int k;
    cin >> k;
    long a[k];
    for (auto &ai:a) cin >> ai;
    long nmin=2, nmax=2;
    for (int i=k-1; i>=0; i--) {
        nmin = ((nmin-1) / a[i] + 1) * a[i];
        nmax = (nmax / a[i] + 1) * a[i] - 1;
        cerr << nmin << ' ' << nmax << '\n';
        if (nmax < nmin) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << nmin << ' ' << nmax << '\n';
    return 0;
}