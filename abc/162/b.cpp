#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    ll n;
    cin >> n;
    ll sum = 0;
    for (ll i=1; i<=n; i++) {
        if (i % 3 != 0 && i % 5 != 0) sum += i;
    }
    cout << sum << '\n';
    return 0;
}