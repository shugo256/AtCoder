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
    for (int i=1; i * 100<=x; i++) {
        if (x <= i * 105) {
            cout << "1\n";
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}