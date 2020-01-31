#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int main() {
    int n;
    cin >> n;
    long a[n], plus=0;
    for (auto &ai:a) {
        cin >> ai;
        if (ai > 0) plus++;
    }
    sort(a, a+n);
    long left = a[n-1], right = a[0], outl[n], outr[n];
    int j = 0;
    if (plus < n-1) {
        for (int i=1; i<n-1 && a[i] <= 0; i++) {
            outl[j] = left;
            outr[j] = a[i];
            left -= a[i];
            j++;
        }
    }
    //cerr << j << '\n';
    if (plus > 0) {
        for (int i=n-2; i>0 && a[i] > 0; i--) {
            outl[j] = right;
            outr[j] = a[i];
            right -= a[i];
            j++;
        }
    }
    outl[j] = left;
    outr[j] = right;
    //cerr << j << '\n';
    cout << left - right << '\n';
    for (int i=0; i<n-1; i++) {
        cout << outl[i] << ' ' << outr[i] << '\n';
    }
    return 0;
}
