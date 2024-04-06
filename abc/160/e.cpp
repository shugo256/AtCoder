#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

using P = pair<ll, int>;
#define fi first
#define se second

int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<P> apple;
    for (int i=0; i<a; i++) {
        ll pi;
        cin >> pi;
        apple.push_back({pi, 0});
    }
    for (int i=0; i<b; i++) {
        ll qi;
        cin >> qi;
        apple.push_back({qi, 1});
    }
    for (int i=0; i<c; i++) {
        ll ri;
        cin >> ri;
        apple.push_back({ri, 2});
    }
    sort(apple.begin(), apple.end(), greater<P>());
    int pi = 0, qi = 0, idx = 0;
    ll ans = 0;
    for (int i=0; i<x+y; i++) {
        while (pi == x && apple[idx].second == 0) idx++;
        while (qi == y && apple[idx].second == 1) idx++;
        ans += apple[idx].first;
        if (apple[idx].second == 0) pi++;
        if (apple[idx].second == 1) qi++;
        idx++;
    }
    cout << ans << '\n';
    return 0;
}