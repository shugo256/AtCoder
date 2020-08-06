#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int red[n+1];
    red[0] = 0;
    for (int i=0; i<n; i++) {
        red[i+1] = red[i] + (s[i] == 'R');
    }
    int ans = n;
    for (int i=0; i<=n; i++) {
        int l = red[i], r = red[n] - l;
        int w2r = i - l, r2w = r;
        ans = min(ans, max(w2r, r2w));
    }
    cout << ans << '\n';
    return 0;
}