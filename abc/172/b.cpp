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
    int n = s.size(), ans = 0;
    for (int i=0; i<n; i++) {
        if (s[i] != t[i]) ans++;
    }
    cout << ans << '\n';
    return 0;
}