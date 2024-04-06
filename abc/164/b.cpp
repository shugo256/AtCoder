#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    while (true) {
        c -= b;
        if (c <= 0) {
            cout << "Yes" << '\n';
            return 0;
        }
        a -= d;
        if (a <= 0) {
            cout << "No" << '\n';
            return 0;
        }
    }
    return 0;
}