#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    int lim = (1 << (h + w));
    vector black(h, vector<bool>(w, false));
    for (int i=0; i<h; i++) {
        string row; cin >> row;
        for (int j=0; j<w; j++) {
            black[i][j] = (row[j] == '#');
        }
    }
    int ans = 0;
    for (int b=0; b<lim; b++) {
        vector red(h, vector<bool>(w, false));
        for (int i=0; i<h+w; i++) {
            if ((b >> i) & 1) {
                if (i < h) {
                    for (int j=0; j<w; j++) red[i][j] = true;
                } else {
                    for (int j=0; j<h; j++) red[j][i-h] = true;
                }
            }
        }
        int cnt = 0;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                if (black[i][j] && !red[i][j]) cnt++;
            }
        }
        if (cnt == k) ans++;
    }
    cout << ans << '\n';
    return 0;
}