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
    cout << (s[2] == s[3] && s[4] == s[5] ? "Yes" : "No") << '\n';
    return 0;
}