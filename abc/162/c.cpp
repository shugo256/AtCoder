#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <numeric>

using ll = long long;

using namespace std;

int main() {
    ll k;
    cin >> k;
    ll sum = 0;
    for (ll i=1; i<=k; i++) {
        for (ll j=1; j<=k; j++) {
            for (ll l=1; l<=k; l++) {
                sum += gcd(i, gcd(j, l));
            }
        }
    }
    cout << sum << '\n';
    return 0;
}