#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    string s;
    cin >> s;
    bool b = false;
    for (auto &c:s) {
        b = !b;
        if ((b && c == 'h') || (!b && c == 'i')) continue;
        else {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << (!b ? "Yes" : "No") << '\n';
    return 0;
}