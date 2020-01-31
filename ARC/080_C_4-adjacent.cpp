#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt4=0, cntx=0;
    bool no2 = true;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        if (a % 4 == 0) cnt4++;
        else if (a % 2 != 0) cntx++;
    }
    if (cnt4 + cntx < n) cntx++;
    cout << (cnt4 + 1 >= cntx ? "Yes" : "No") << '\n';
    return 0;
}