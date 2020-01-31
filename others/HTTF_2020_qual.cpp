#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <functional>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

#define INF 100000000

struct grid {
    int turn;
    char dir;
    P next;
};

struct coord {
    P p;
    grid g;
};

struct robot {
    int x, y;
    char dir;
};

string dirs = "LURD";

map<char, P> vec = {
    {'D', P{1,  0}},
    {'U', P{-1, 0}},
    {'R', P{0,  1}},
    {'L', P{0, -1}}
};

int n, m, b, gx, gy;

void operator+=(P& p1, const P& p2) { 
    p1.fi = (p1.fi + p2.fi + n) % n;
    p1.se = (p1.se + p2.se + n) % n;
}

void operator-=(P& p1, const P& p2) { 
    p1.fi = (p1.fi - p2.fi + 2*n) % n;
    p1.se = (p1.se - p2.se + 2*n) % n;
}

P operator+(const P& p1, const P& p2) { 
    P ans = p1;
    ans += p2;
    return ans;
}

P operator-(const P& p1, const P& p2) { 
    P ans = p1;
    ans -= p2;
    return ans;
}

int main() {
    cin >> n >> m >> b >> gx >> gy;
    grid field[n][n];
    robot R[m];
    for (auto &r:R) cin >> r.x >> r.y >> r.dir;
    fill(field[0], field[n], grid{INF, ' ', P{-1, -1}});
    field[gx][gy].dir = '@';
    bool used[n][n];
    fill(used[0], used[n], false);
    for (int i=0, bx, by; i<b; i++) {
        cin >> bx >> by;
        used[bx][by] = true;
    }
    // deque<coord> dq;
    // used[gx][gy] = true;
    // for (auto &d:dirs) {
    //     P p = P{gx, gy} - vec[d];
    //     if (used[p.fi][p.se]) continue;
    //     grid g = grid{0, d, P{gx, gy}};
    //     dq.push_back(coord{p, g});
    //     used[p.fi][p.se] = true;
    //     field[p.fi][p.se] = g;
    // }
    // while (!dq.empty()) {
    //     coord from = dq.front(); dq.pop_front();
    //     for (auto &d:dirs) {
    //         coord to = from;
    //         to.p -= vec[d];
    //         if (used[to.p.fi][to.p.se]) continue;
    //         used[to.p.fi][to.p.se] = true;
    //         if (d != from.g.dir) {
    //             to.g.turn++;
    //             to.g.next = from.p;
    //             to.g.dir = d;
    //             dq.push_back(to);
    //             field[to.p.fi][to.p.se] = to.g;
    //         } else {
    //             dq.push_front(to);
    //             field[to.p.fi][to.p.se] = to.g;
    //         }
    //     }
    // }
    int stream = -1;
    for (int i=0; i<4; i++) {
        char d = dirs[i];
        P check = P{gx, gy} - vec[d];
        if (!used[check.fi][check.se]) {
            stream = i;
            break;
        }
    }
    if (stream == -1) {
        cout << 0 << '\n';
        break;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (used[i][j]) continue;
            for (int k=0; k<4; k++) {
                P next = P{i, j} + vec[dirs[(stream + k) % 4]];
                if (!used[next.fi][next.se]) {
                    
                }
            }
        }
    }
    vector<robot> ans;
    fill(used[0], used[n], false);
    used[gx][gy] = true;
    for (auto &ri:R) {
        robot r = ri;
        if (field[r.x][r.y].next.fi < 0) continue;
        vector<robot> add;
        while (!(r.x == gx && r.y == gy)) {
            grid jump = field[r.x][r.y];
            if (r.dir != jump.dir && !used[r.x][r.y]) {
                r.dir = jump.dir;
                add.push_back(r);
            }
            // cerr << r.x << ' ' << r.y << ' ' << r.dir << ' ' << field[r.x][r.y].next.fi << ' ' << field[r.x][r.y].next.se << '\n';
            r.x = jump.next.fi;
            r.y = jump.next.se;
        }
            // cerr << "TRUE" << '\n';
        char prev = '\0';
        for (auto &ai:add) {
            if (used[ai.x][ai.y] || prev == ai.dir) continue;
            ans.push_back(ai);
            used[ai.x][ai.y] = true;
            prev = ai.dir;
        }
    }
    cout << ans.size() << '\n';
    for (auto &a:ans) {
        cout << a.x << ' ' << a.y << ' ' << a.dir << '\n';
    }
    for (auto &f:field) {
        for (auto &fie:f) {
            cerr << fie.dir;
        }
        cerr << '\n';
    }
    return 0;
}