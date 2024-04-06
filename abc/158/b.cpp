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
    cout << (n / (a + b)) * a + min(a, n % (a + b)) << '\n';
    return 0;
}