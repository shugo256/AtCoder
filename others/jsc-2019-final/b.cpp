#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>

using ll = long long;

using namespace std;

#define bs bitset<300>

int main() {
    int n;
    string a;
    cin >> n;
    vector<int> xy[n], yx[n];
    for (int i=0; i<n; i++) {
        cin >> a;
        for (int j=0; j<n; j++) {
            if (a[j] == '1') {
                xy[i].push_back(j);
                yx[j].push_back(i);
            }
        }
    }
    bs xz[n], yz[n];
    for (auto &xzi:xz)
        cin >> xzi;
    for (int i=0; i<n; i++) {
        yz[i].set();
        for (auto &xj:yx[i])
            yz[i] &= xz[xj];
    }
    for (int i=0; i<n; i++) {
        bs xzi_p;
        xzi_p.reset();
        for (auto &yj:xy[i])
            xzi_p |= yz[yj];
        if (xzi_p != xz[i]) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for (auto &yzi:yz)
        cout << yzi.to_string().substr(300-n, n) << '\n';
    return 0;
}