#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, v, p;
    ll m;
    cin >> n >> m >> v >> p;
    int w = n - v;
    ll a[n]; for (auto &ai:a) cin >> ai;
    sort(a, a+n, greater<ll>());
    int cnt=p;
    ll rui[n+1], prev = a[p-1];
    rui[0] = 0;
    for (int i=0; i<n; i++) rui[i+1] = rui[i] + a[i];
    while (true) {
        while (cnt < n && a[cnt] == prev) cnt++;
        if (cnt == n || a[p-1] > a[cnt] + m || rui[cnt] - rui[p-1] - a[cnt] * (cnt - p + 1) > w*m)
            break;
        prev = a[cnt];
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}