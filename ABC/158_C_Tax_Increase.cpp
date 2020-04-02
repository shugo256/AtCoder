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
    for (int i=1; i<=2000; i++) {
        if ((int)(1.08 * i) - i == a && (int)(1.10 * i) - i == b) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}