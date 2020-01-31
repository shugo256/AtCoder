#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int k, x;
    cin >> k >> x;
    cout << (500 * k >= x ? "Yes" : "No") << '\n';
    return 0;
}