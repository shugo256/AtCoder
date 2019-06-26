#include <iostream>
#include <algorithm>

using namespace std;

//いったん諦め

int main() {
    int l;
    cin >> l;
    int a[l];
    for (auto &ai:a) cin >> ai;
    int suml[l+1], sumr[l+1],
        oddl[l+1], oddr[l+1];
    suml[0] = oddl[0] = 0;
    sumr[l] = oddr[l] = 0;
    for (int i=0; i<l; i++) {
        oddl[i+1] = oddl[i] + (a[i] % 2);
        oddr[l-i-1] = oddr[l-i] + (a[l-i-1] % 2);
    }
    int best = 200010;
    for (int i=0; i<l; i++) {
        int oe = oddl[i] + l - i - oddr[i],
            eo = oddr[i] + l - i - oddl[i];
        best = min({best, oe, eo}); 
    }
    cout << best << '\n';
    return 0;
}