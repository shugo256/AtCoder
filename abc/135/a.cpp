#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    long a, b;
    cin >> a >> b;
    if ((a + b) % 2) cout << "IMPOSSIBLE" << '\n';
    else
        cout << (a + b) / 2 << '\n';
    return 0;
}