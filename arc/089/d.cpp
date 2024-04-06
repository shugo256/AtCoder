#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> sub(4 * k, vector<int>(4 * k, 0)),
                        kanae(4 * k + 1, vector<int>(4 * k + 1, 0));
    for (int i=0; i<n; i++) {
        int x, y; char c;
        cin >> x >> y >> c;
        if (c == 'B') x += k;
        x %= (2*k);
        y %= (2*k);
        int x1 = x,
            y1 = y,
            x2 = x+k,
            y2 = y+k,
            x3 = x+2*k,
            y3 = y+2*k;
        sub[x1][y1]++;
        sub[x1][y2]--;
        sub[x2][y1]--;
        sub[x2][y2]+=2;
        sub[x2][y3]--;
        sub[x3][y2]--;
        sub[x3][y3]++;
    }
    // for (auto &si:sub) {
    //     for (auto s:si) {
    //         cerr << (s >= 0 ? s : 2) << ' ';
    //     }
    //     cerr << endl;
    // }
    int best = 0;
    for (int i=0; i<4*k; i++) {
        for (int j=0; j<4*k; j++) {
            kanae[i+1][j+1] = sub[i][j] + kanae[i+1][j] + kanae[i][j+1] - kanae[i][j];
            if (i >= 2*k && j >= 2*k) {
                int x1 = i+1,
                    y1 = j+1,
                    x2 = i+1-2*k,
                    y2 = j+1-2*k;
                best = max(best, kanae[x1][y1] + 
                                 kanae[x1][y2] + 
                                 kanae[x2][y1] + 
                                 kanae[x2][y2]);
            }
        }
    }
    cout << best << '\n';
    return 0;
}