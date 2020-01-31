#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long a, b;
        cin >> a >> b;
        if (a == b) cout << -1 << '\n';
        else cout << abs(a - b) << endl;
    }
    return 0;
}
