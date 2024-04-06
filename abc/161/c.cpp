#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    cout << min(n % k, k - n % k) << '\n';
    return 0;
}