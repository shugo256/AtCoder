#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

using P = pair<string, string>;
#define fi first
#define se second

int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    ll ans = 0;
    for (int i=1; i<n; i++) {
        for (int j=1; i + j*2 < n; j++) {
            if (s.substr(i, j) != s.substr(i+j, j)) continue;
            int k = i + j*2, s2 = i-1, s6 = n-1;
            while (s2 > 0 && s6 > k && s[s2] == s[s6]) {
                s2--; s6--;
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}