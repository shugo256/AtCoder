#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int x;
    cin >> x;
    cout << (x / 500) * 1000 + ((x % 500) / 5) * 5 << '\n';
    return 0;
}