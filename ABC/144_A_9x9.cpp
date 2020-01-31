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
    cout << (a < 10 && b < 10 ? a * b : -1) << '\n';
    return 0;
}