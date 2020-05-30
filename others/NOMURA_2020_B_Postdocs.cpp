#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    string t; cin >> t;
    for (auto &c:t) {
        if (c == '?') c = 'D';
    }
    cout << t << '\n';
    return 0;
}