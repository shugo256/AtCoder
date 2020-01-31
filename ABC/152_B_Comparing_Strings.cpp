#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    char a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    cout << string(b - '0', a) << '\n';
    return 0;
}