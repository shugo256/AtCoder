#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

using P = pair<long, long>;

int main() {
    int n;
    cin >> n;
    vector<P> rects;
    for (int i = 0; i < n; i++) {
        long a, b; cin >> a >> b;
        rects.push_back(minmax(a, b));
    }
    sort(rects.begin(), rects.end(), [](P l, P r) {
        return l.first > r.first || (l.first == r.first && l.second < r.second);
    });
    vector<P> dp;
    for (auto r:rects) {
        auto pp = partition_point(dp.begin(), dp.end(), [&](P p) {
            return p.first > r.first && p.second > r.second;
        });
        if (pp == dp.end()) dp.push_back(r);
        else if (pp->second < r.second) *pp = r;
    }
    cout << dp.size() << '\n';
    return 0;
}
