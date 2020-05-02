#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    ll x;
    cin >> x;
    ll yokin = 100;
    for (int i=1; true; i++) {
        yokin = (ll)(1.01 * yokin);
        if (yokin >= x) {
            cout << i << '\n';
            return 0;
        }
    }
}