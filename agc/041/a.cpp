#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    cout << ((b - a) % 2 ? min(a + (b - a - 1) / 2, n - b + 1 + (n - (a + n - b + 1)) / 2) : (b - a) / 2) << '\n';
    return 0;
}