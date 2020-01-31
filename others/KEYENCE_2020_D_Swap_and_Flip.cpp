#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <cmath>
#include <cassert>

using ll = long long;

using namespace std;

using P = pair<bool, int>;
#define fi first
#define se second

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (auto &ai:a) cin >> ai;
    for (auto &bi:b) cin >> bi;
    int ans = 10000;
    int vals[n];
    for (int i=0; (i >> n) == 0; i++) {
        set<int> cards[51][2];
        for (int j=0; j<n; j++) {
            if ((i >> j) & 1) {
                vals[j] = a[j];
                cards[a[j]][j % 2].insert(j);
            } else {
                vals[j] = b[j];
                cards[b[j]][(j+1) % 2].insert(j);
            }
        }
        sort(vals, vals+n);
        int cnt = 0;
        for (int j=0; j<n; j++) {
            if (cards[vals[j]][j%2].empty()) {
                cnt = 10000;
                break;
            }
            auto itr = cards[vals[j]][j%2].begin();
            cards[vals[j]][j%2].erase(itr);
            vals[j] = *itr;
        }
        for (int i=0; i<n; i++) {
            for (int j=n-1; j>i; j--) {
                if (vals[j] < vals[j-1]) {
                    swap(vals[j], vals[j-1]);
                    cnt++;
                }
            }
        }
        ans = min(ans, cnt);
    }
    cout << (ans < 10000 ? ans : -1) << '\n';
    return 0;
}