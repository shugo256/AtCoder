#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

int main() {
    int n;
    cin >> n;
    vector<P> rain;
    for (int i=0, a, b; i<n; i++) {
        char c;
        cin >> a >> c >> b;
        a -= a % 5;
        b += (5 - b % 5) % 5;
        if (b % 100 == 60) b += 40;
        rain.push_back({a, 1});
        rain.push_back({b, -1});
    }
    sort(rain.begin(), rain.end(), [](P a, P b) {
        return (a.fi == b.fi ? a.se > b.se : a.fi < b.fi);
    });
    int cnt = 0;
    for (auto &ri:rain) {
        if (cnt == 0) cout << setw(4) << setfill('0') << ri.fi << '-';
        cnt += ri.se;
        if (cnt == 0) cout << setw(4) << setfill('0') << ri.fi << '\n';
    }
    return 0;
}