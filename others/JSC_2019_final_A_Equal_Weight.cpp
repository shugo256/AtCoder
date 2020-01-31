#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (auto &ai:a) cin >> ai;
    for (auto &bi:b) cin >> bi;
    map<int, P> mp;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int sum = a[i] + b[j];
            if (mp.count(sum)) {
                cout << mp[sum].fi << ' ' << mp[sum].se << ' ' << i << ' ' << j << endl;
                return 0;
            }
            mp[sum] = P{i, j};
        }
    }
    cout << -1 << '\n';
    return 0;
}