#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

#define amax(a, b) a = max(a, b)

using P = pair<int, int>;
#define fi first
#define se second

int main() {
    int h, w, m;
    cin >> h >> w >> m;
    int cnt_x[h], cnt_y[w];
    fill(cnt_x, cnt_x+h, 0);
    fill(cnt_y, cnt_y+w, 0);
    set<P> st;
    int xmax = 0, ymax = 0;
    for (int i=0, hi, wi; i<m; i++) {
        cin >> hi >> wi;
        hi--; wi--;
        st.insert(P{hi, wi});
        cnt_x[hi]++;
        cnt_y[wi]++;
        amax(xmax, cnt_x[hi]);
        amax(ymax, cnt_y[wi]);
    }
    vector<int> xbests, ybests;
    for (int i=0; i<h; i++) {
        if (cnt_x[i] == xmax) {
            xbests.push_back(i);
        }
    }
    for (int i=0; i<w; i++) {
        if (cnt_y[i] == ymax) {
            ybests.push_back(i);
        }
    }
    if ((ll)xbests.size() * ybests.size() > (ll)m) {
        cout << xmax + ymax << '\n';
    } else {
        bool hole = false;
        for (auto &xi:xbests) {
            for (auto &yi:ybests) {
                if (st.count(P{xi, yi}) == 0) hole = true;
            }
        }
        cout << xmax + ymax - (int)(!hole) << '\n';
    }
    return 0;
}