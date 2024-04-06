#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

struct P{
    long fi, se, th;
};

#define INF ((long)2e9)
#define div(a, b) ((a + b * INF) / b - INF)

int main() {
    int n;
    cin >> n;
    vector<long> a(n), b(n);
    for (auto &ai:a) cin >> ai;
    for (auto &bi:b) cin >> bi;
    long ans[n]; ans[0] = -INF;
    vector<P> grads;
    grads.push_back({-INF, 0, 0});
    grads.push_back({INF, 0, 0});
    for (int i=1; i<n; i++) {
        auto ppb = partition_point(grads.begin(), grads.end(), [&](P p) {
            return b[i] > b[p.th] + p.fi * (i - p.th);
        });
        if (ppb == grads.end()) {
            // 高すぎて範囲外
            grads.push_back({b[i] - b[i-1], i-1, i});
        } 
        else if (ppb == grads.begin()) {
            // 低すぎて範囲外
            grads = vector<P>();
            grads.push_back({-INF, i, i});
            grads.push_back({INF, i, i});
            ans[i] = ans[i-1];
            cout << ans[i] << '\n';
            continue;
        }
        else {
            // 範囲内、上側の調整
            ppb++;
            grads.erase(ppb, grads.end());
            P &gb = grads.back();
            gb.fi = div((b[i] - b[gb.se] + i - gb.se - 1), (i - gb.se));
            gb.th = i;
        }
        auto ppa = partition_point(grads.begin(), grads.end(), [&](P p) {
            return a[i] >= b[p.th] + p.fi * (i - p.th);
        });
        if (ppa != grads.begin()) ppa--;
        grads.erase(grads.begin(), ppa);
        P &gf = grads.front();
        if (a[i] > b[gf.th] + gf.fi * (i - gf.th)) {
            gf.fi = div((a[i] - b[gf.th] + i - gf.th - 1), (i - gf.th));
            gf.se = gf.th;
        }
        ans[i] = max(ans[i-1], gf.fi);
        cout << ans[i] << '\n';
    }
    return 0;
}