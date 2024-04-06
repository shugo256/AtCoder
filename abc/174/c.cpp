#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int k;
    cin >> k;
    int r = 0;
    for (int i=1; i<=k; i++) {
        r = (r * 10 + 7) % k;
        if (r == 0) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}