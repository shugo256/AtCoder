#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

#define INF 10000000

struct snuke {
    int x, y, dir;
    P dist;
};

vector<P> direction{
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

int main() {
    int h, w, k, x1, y1, x2, y2;
    cin >> h >> w >> k >> x1 >> y1 >> x2 >> y2;
    x1--; x2--; y1--; y2--;
    vector d(h, vector(w, vector<P>(4, {INF, INF})));
    vector grid(h, vector(w, false));
    for (int i=0; i<h; i++) {
        string s; cin >> s;
        for (int j=0; j<w; j++) {
            if (s[j] == '@') {
                grid[i][j] = true;
            }
        }
    }
    priority_queue<snuke, vector<snuke>, function<bool(snuke, snuke)>> pq([](snuke a, snuke b) {
        return a.dist > b.dist;
    });
    pq.push({x1, y1, 0, {0, 0}});
    d[x1][y1][0] = {0, 0};
    while (!pq.empty()) {
        snuke f = pq.top(); pq.pop();
        if (f.dist > d[f.x][f.y][f.dir]) continue;
        if (f.x == x2 && f.y == y2) {
            cout << f.dist.fi + (f.dist.se > 0) << '\n';
            return 0;
        }
        P newd = {f.dist.fi + (f.dist.se > 0), 0};
        for (int dir=0; dir<4; dir++) {
            if (newd < d[f.x][f.y][dir]) {
                d[f.x][f.y][dir] = newd;
                pq.push({f.x, f.y, dir, newd});
            }
        }
        f.x += direction[f.dir].fi;
        f.y += direction[f.dir].se;
        f.dist.se++;
        if (f.dist.se > k) {
            f.dist.fi += f.dist.se / k;
            f.dist.se %= k;
        }
        if (0 <= f.x && f.x < h && 0 <= f.y && f.y < w && f.dist < d[f.x][f.y][f.dir] && !grid[f.x][f.y]) {
            d[f.x][f.y][f.dir] = f.dist;
            pq.push(f);
        }
    }
    cout << -1 << '\n';
    return 0;
}
