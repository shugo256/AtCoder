#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    string s, t, ans;
    cin >> n >> s >> t;
    for (int i=0; i<2*n; i++) {
        if (i % 2) ans += t[i/2];
        else ans += s[i/2];
    }
    cout << ans << '\n';
    return 0;
}