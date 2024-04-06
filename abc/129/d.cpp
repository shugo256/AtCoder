#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<int> yoko[h], tate[w];
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            char c; cin >> c;
            if (c == '#') {
                yoko[i].push_back(j);
                tate[j].push_back(i);
            }
        }
    }
    int lamp[h][w];
    for (int i=0; i<h; i++) {
        yoko[i].push_back(w);
        int now=-1;
        for (auto yij:yoko[i]) {
            for (int k=now+1; k<yij; k++) {
                lamp[i][k] = yij - now - 1;
            }
            now = yij;
            if (now < w) lamp[i][now] = 0;
        }
    }
    int best=0;
    for (int i=0; i<w; i++) {
        tate[i].push_back(h);
        int now=-1;
        for (auto tij:tate[i]) {
            for (int k=now+1; k<tij; k++)
                best = max(best, lamp[k][i] + tij - now - 1);
            now = tij;
        }
    }
    cout << best - 1 << '\n';
    return 0;
}

