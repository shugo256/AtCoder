#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> yoko(h);
    bool map[2001][2001] = {{0}};
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            char c; cin >> c;
            if (c == '#') {
                yoko[i].push_back(j);
                map[i][j] = true;
            }
            map[h][j] = true;
        }
    }
    int lamp[h][w];
    for (int i=0; i<h; i++) {
        yoko[i].push_back(w);
        int now=-1;
        size_t len = yoko[i].size();
        for (size_t j=0; j<len; j++) {
            for (int k=now+1; k<yoko[i][j]; k++) {

                //// cerr << i << ' ' << j << ' ' << k << ' ' << yoko[i][j] << endl;
                lamp[i][k] = yoko[i][j] - now - 1; 
            }
            now = yoko[i][j];
            lamp[i][now] = 0;
        }
    }
    int best=0;
    for (int j=0; j<w; j++) {
        int cnt=0, b=0;
        for (int i=0; i<=h; i++) {
            if (map[i][j]) {
                best = max(best, b + cnt);
                cnt = b = 0;
            } else {
                cnt++;
                b = max(b, lamp[i][j]);
            }
        }
    }
    cout << best - 1 << '\n';
    return 0;
}
