#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using ll = long long;

using namespace std;

#define EPS (1e-13)

struct pixel {
    int x, y, t;
};

double rate(int i) {
    if (i <= 0) return 1;
    else {
        double r = rate(i / 2);
        return r * r * (i % 2 ? 0.99 : 1);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    string c[n]; 
    int sx, sy, gx, gy;
    for (int i=0; i<n; i++) {
        cin >> c[i];
        for (int j=0; j<m; j++) {
            if (c[i][j] == 's') {
                sx = i; sy = j;
            } 
            if (c[i][j] == 'g') {
                gx = i; gy = j;
            }
        }
    }
    double l = -1, r = 10;
    while (r - l > EPS) {
        double akari = (l + r) / 2;
        bool visit[n][m];
        fill(visit[0], visit[n], false);
        queue<pixel> q;
        q.push({sx, sy, 1});
        visit[sx][sy] = true;
        while (!q.empty()) {
            pixel f = q.front(); q.pop();
            for (int x=max(f.x-1, 0); x<=min(f.x+1, n-1); x++) {
                for (int y=max(f.y-1, 0); y<=min(f.y+1, m-1); y++) {
                    if ((x != f.x && y != f.y) || (c[x][y] == '#')) continue;
                    if (c[x][y] == 'g') {
                        visit[x][y] = true;
                        continue;
                    }
                    double bright = (double)(c[x][y] - '0') * rate(f.t);
                    if (visit[x][y] || bright < akari) continue;
                    visit[x][y] = true;
                    q.push({x, y, f.t+1});
                }
            }
        }
        if (visit[gx][gy]) {
            l = akari;
        } else {
            r = akari;
        }
    }
    cout << setprecision(15) << l << '\n';
    return 0;
}