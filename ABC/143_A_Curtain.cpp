#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << max(a - 2*b, 0) << '\n';
    return 0;
}