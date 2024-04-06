#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define LIMIT ((ll)1e18)

int main() {
    int n;
    cin >> n;
    ll ans = 1;
    bool overFlow = false;
    for (int i=0; i<n; i++) {
        ll ai; cin >> ai;
        if (ai == 0) {
            cout << 0 << '\n';
            return 0;
        }
        if (ans > LIMIT / ai + 1) {
            overFlow = true;
        }
        if (!overFlow)
            ans *= ai;
    }
    cout << ((ans <= LIMIT && !overFlow) ? ans : -1) << '\n';
    return 0;
}