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
    int ans = 0;
    for (int i=0, ai; i<n; i++) {
        cin >> ai;
        if (i % 2 == 0 && ai % 2 == 1) ans++;
    }
    cout << ans << '\n';
    return 0;
}