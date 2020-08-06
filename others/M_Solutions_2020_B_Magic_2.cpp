#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    while (a >= b) {
        b <<= 1;
        k--;
    }
    while (b >= c) {
        c <<= 1;
        k--;
    }
    cout << (k >= 0 ? "Yes" : "No") << '\n';
    return 0;
}