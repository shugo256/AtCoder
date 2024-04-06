#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

bool check(string &s) {
    int n = s.size();
    string r = s;
    reverse(s.begin(), s.end());
    for (int i=0; i<n; i++) {
        if (r[i] != s[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string t = s.substr(0, (n-1)/2);
    string u = s.substr((n+3) / 2 - 1);
    cout << (check(s) && check(t) && check(u) ? "Yes" : "No") << '\n';
    return 0;
}