#include <iostream>
#include <algorithm>
#include <set>
#include <numeric>
#include <iomanip>

using namespace std;

using P = pair<int, long>;

int main() {
    int n, m;
    cin >> n >> m;
    P cities[m];
    for (auto &c:cities) 
        cin >> c.first >> c.second;
    int ids[m];
    iota(ids, ids+m, 0);
    sort(ids, ids+m, [&](int l, int r) {
        return cities[l] < cities[r];
    });
    P ans[m];
    int prev = 0;
    long cnt = 0;
    for (auto i:ids) {
        P now = cities[i];
        if (prev != now.first) cnt = 1;
        ans[i] = {now.first, cnt};
        cnt++;
        prev = now.first;
    }
    cout << setfill('0') << right;
    for (auto a:ans) cout << setw(6) << a.first << setw(6) << a.second << '\n';
    return 0;
}