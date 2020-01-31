#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

int main() {
    int n, k;
    map<char, int> m;
    string s;
    cin >> n >> k >> m['s'] >> m['p'] >> m['r'] >> s;
    int ans=0;
    for (int i=0; i<n; i++) {
        if (i >= k && s[i] == s[i-k]) {
            s[i] = '-';
            continue;
        }
        ans += m[s[i]];
    }
    cout << ans << '\n';
    return 0;
}