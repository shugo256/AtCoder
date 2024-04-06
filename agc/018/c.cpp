#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

struct coin{ ll a, b, c; };

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    vector<coin> coins(x + y + z);
    for (auto &ci:coins) {
        cin >> ci.a >> ci.b >> ci.c;
    }
    sort(coins.begin(), coins.end(), [](coin l, coin r) {
        return l.a - l.b > r.a - r.b;
    });
    auto cmpac = [](coin l, coin r) {
        return l.a - l.c > r.a - r.c;
    };
    auto cmpbc = [](coin l, coin r) {
        return l.b - l.c > r.b - r.c;
    };
    priority_queue<coin, vector<coin>, decltype(cmpac)> acpq(cmpac);
    priority_queue<coin, vector<coin>, decltype(cmpbc)> bcpq(cmpbc);
    ll prev = 0;
    for (int i=0; i<x; i++) {
        acpq.push(coins[i]);
        prev += coins[i].a;
    }
    vector<ll> cnt(z+1, prev);
    for (int i=0; i<z; i++) {
        if (cmpac(acpq.top(), coins[i+x])) {
            prev += coins[i+x].c;
        } else {
            prev -= acpq.top().a;
            prev += acpq.top().c;
            prev += coins[i+x].a;
            acpq.pop();
            acpq.push(coins[i+x]);
        }
        cnt[i+1] = prev;
    }
    prev = 0;
    for (int i=x+y+z-1; i>=x+z; i--) {
        bcpq.push(coins[i]);
        prev += coins[i].b;
    }
    ll ans = cnt[z] + prev;
    for (int i=z-1; i>=0; i--) {
        if (cmpbc(bcpq.top(), coins[i+x])) {
            prev += coins[i+x].c;
        } else {
            prev -= bcpq.top().b;
            prev += bcpq.top().c;
            prev += coins[i+x].b;
            bcpq.pop();
            bcpq.push(coins[i+x]);
        }
        ans = max(ans, cnt[i] + prev);
    }
    cout << ans << '\n';
    return 0;
}