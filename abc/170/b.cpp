#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    for (int c = 0; c <= 100; c++) {
        for (int t = 0; t <= 100; t++) {
            if (c + t == x && c * 2 + t * 4 == y) {
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}