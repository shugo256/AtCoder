#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int k;
    cin >> k;
    queue<ll> q;
    for (int i=1; i<10; i++) q.push(i);
    ll ans;
    for (int i=0; i<k; i++) {
        ans = q.front(); q.pop();
        ll d = ans % 10;
        for (int j=max(d-1, 0ll); j<=d+1 && j<10; j++) q.push(ans * 10+ j);
    }
    cout << ans << '\n';
    return 0;
}