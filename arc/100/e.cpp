#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <functional>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    int p = 1 << n;
    vector<long> a(p);
    for (auto &ai:a) cin >> ai;
    int top2[p][2];
    fill(top2[0], top2[p], -1);
    for (int i=0; i<p; i++) top2[i][0] = i;
    for (int i=0; i<p; i++) {
        for (int j=0; j<n; j++) {
            if (!(i & (1 << j))) continue;
            int arr[] = {
                top2[i][0],
                top2[i][1],
                top2[i-(1<<j)][0],
                top2[i-(1<<j)][1]
            };
            sort(arr, arr+4, [&](int l, int r) {
                if (l == -1) return false;
                if (r == -1) return true;
                return a[l] > a[r];
            });
            auto pnt = arr;
            top2[i][0] = *arr;
            while (*pnt == arr[0]) pnt++;
            top2[i][1] = *pnt;
        }
    }
    set<int, function<bool(int, int)>> s([&](int l, int r) {
        if (l == -1) return false;
        if (r == -1) return true;
        return a[l] > a[r];
    });
    s.insert(6);
    s.insert(7);
    // cerr << s.size() << '\n';
    long ans = 0;
    for (int i=1; i<p; i++) {
        // cerr << top2[i][0] << ' ' << top2[i][1] << '\n';
        ans = max(ans, a[top2[i][0]] + a[top2[i][1]]);
        cout << ans << '\n';
    }
    return 0;
}