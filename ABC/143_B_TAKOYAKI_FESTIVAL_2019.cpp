#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    int d[n];
    for (auto &di:d) cin >> di;
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            ans += d[i] * d[j];
        }
    }
    cout << ans << '\n';
    return 0;
}