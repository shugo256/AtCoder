#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int,int> P;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    bool open[h][w];
    int dist[h][w], xy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    fill(dist[0], dist[h], k+1);
    queue<P> q;
    for (int i = 0; i < h; i++) {
        char a;
        for (int j=0; j<w; j++) {
            cin >> a;
            open[i][j] = (a == '.');
            if (a == 'S') {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        P now = q.front(); q.pop();
        int d = dist[now.first][now.second];
        if (d == k) break;
        for (int i=0; i<4; i++) {
            int x = now.first  + xy[i][0],
                y = now.second + xy[i][1];
            if (0 <= x && x < h && 0 <= y && y < w && open[x][y]) {
                open[x][y] = false;
                dist[x][y] = d + 1;
                q.push({x, y});
            }
        }
    }
    int magic = 100000;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (dist[i][j] > k) continue;
            magic = min( {magic, (i+k-1)/k, (j+k-1)/k, (h-i+k-2)/k, (w-j+k-2)/k} );
        }
    }
    cout << magic + 1 << '\n';
    return 0;
}