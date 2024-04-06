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
    bool odd = true;
    for (auto c:s) {
        if ((odd && c == 'L') || (!odd && c == 'R')) {
            cout << "No" << '\n';
            return 0;
        }
        odd = !odd;
    }
    cout << "Yes" << '\n';
    return 0;
}