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
    int n = s.size(), m = t.size();
    int ans = n;
    for (int i=0; i<=n-m; i++) {
        int dif = 0;
        for (int j=0; j<m; j++) {
            if (s[i+j] != t[j]) {
                dif++;
            }
        }
        ans = min(ans, dif);
    }
    cout << ans << '\n';
    return 0;
}