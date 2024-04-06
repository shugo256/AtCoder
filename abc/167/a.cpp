#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    cout << (t.substr(0, s.size()) == s ? "Yes" : "No") << '\n';
    return 0;
}