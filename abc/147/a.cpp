#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + b + c >= 22 ? "bust" : "win") << '\n';
    return 0;
}