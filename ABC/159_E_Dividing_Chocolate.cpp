#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int rui[20][1010] = {{0}};

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            char c; cin >> c;
            rui[i][j] = c - '0';
        }
    }
    for (int i=0; i<=h; i++) {
        for (int j=0; j<w; j++) {
            rui[i][j+1] += rui[i][j];
        }
    }
    for (int j=0; j<=w; j++) {
        for (int i=0; i<h; i++) {
            rui[i+1][j] += rui[i][j];
        }
    }
    int lim = (1 << (h-1));
    int ans = h + w;
    for (int b=0; b<lim; b++) {
        vector<int> ends;
        for (int i=0; i<h-1; i++) if (b & (1 << i)) ends.push_back(i);
        ends.push_back(h-1);
        int sj = 0, cnt = ends.size()-1;
        for (int j=0; j<w; j++) {
            int si = 0;
            for (auto &ei:ends) {
                int val = rui[ei+1][j+1] - rui[si][j+1] - rui[ei+1][sj] + rui[si][sj];
                if (val > k) {
                    if (sj == j) cnt = h + w;
                    sj = j;
                    cnt++;
                    break;
                } 
                si = ei+1;
            }
        }
        ans = min(ans, cnt);
        // cerr << cnt << ' ' << b << '\n';
    }
    cout << ans << '\n';
    return 0;
}