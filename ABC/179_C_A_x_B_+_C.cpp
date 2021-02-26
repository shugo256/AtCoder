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
    for (int a=1; a<=n; a++) {
        ans += n / a;
        if (n % a == 0) ans--;
    }
    cout << ans << '\n';
    return 0;
}