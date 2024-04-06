#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int a[n], best = 0;
    for (auto &ai:a) (cin >> ai, best = max(best, ai));
    int ans=0;
    for (auto &ai:a) if (ai + x >= best) ans++;
    cout << ans << '\n';
    return 0;
}