#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    ll n;
    cin >> n;
    ll cnt[10][10] = {{0}};
    for (int i=1; i<=n; i++) {
        int f = (to_string(i)[0] - '0'),
            l = i % 10;
        cnt[f][l]++;
    }
    ll ans = 0;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            ans += cnt[i][j] * cnt[j][i];
        }
    }
    cout << ans << '\n';
    return 0;
}