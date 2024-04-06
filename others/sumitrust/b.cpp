#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        double d = 1.08 * i;
        if (n == (int)d) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << ":(" << '\n';
    return 0;
}