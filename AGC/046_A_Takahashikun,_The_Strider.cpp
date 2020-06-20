#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <numeric>

using ll = long long;

using namespace std;

int main() {
    int x;
    cin >> x;
    cout << lcm(x, 360) / x << '\n';
    return 0;
}