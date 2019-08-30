#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int base[] = {12, 16, 11};
int cnt[]  = { 0,  0,  0};

bool isSquare(int x) {
    int r = sqrt(x);
    return x == r * r;
}

struct point{ int x, y; };
bool operator==(const point& l, const point& r) {
    return l.x == r.x && l.y == r.y;
}

int main() {
    int h, w;
    cin >> h >> w;
    bool grid[h][w];
    for (auto &gi:grid) {
        for (auto &gij:gi) {
            char c; cin >> c;
            gij = (c == 'o');
        }
    }
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (!grid[i][j]) continue;
            int size = 0;
            queue<point> q;
            q.push({i, j});
            while (!q.empty()) {
                point p = q.front(); q.pop();
                if (!grid[p.x][p.y]) continue;
                size++;
                grid[p.x][p.y] = false;
                for (int nx=p.x-1; nx<=p.x+1; nx++) {
                    if (nx < 0 || nx >= h) continue;
                    for (int ny=p.y-1; ny<=p.y+1; ny++) {
                        if (ny < 0 || ny >= w || !grid[nx][ny]) continue;
                        q.push({nx, ny});
                    }
                }
            }
            for (int k=0; k<3; k++) {
                if (size % base[k] == 0 && isSquare(size / base[k])) {
                    cnt[k]++;
                    break;
                }
            }
        }
    }
    cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << '\n';
    return 0;
}