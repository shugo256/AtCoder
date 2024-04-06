#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    cout << min(b-1, n) * a / b << '\n';
    return 0;
}