#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, x, t;
    cin >> n >> x >> t;
    cout << (n + x - 1) / x * t << '\n';
    return 0;
}