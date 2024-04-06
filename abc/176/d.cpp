#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define INF 1000000000

using P = pair<int, int>;
#define fi first
#define se second

int d[1010][1010] = {{0}};
bool visited[1010][1010] = {{0}};

bool in_range(P p, int h, int w) {
    return (0 <= p.fi && p.fi < h && 0 <= p.se && p.se < w);
}

int main() {
    int h, w;
    P start, goal;
    cin >> h >> w >> start.fi >> start.se >> goal.fi >> goal.se;
    start.fi--; start.se--;
    goal.fi--; goal.se--;
    for (int i=0; i<h; i++) {
        string s; cin >> s;
        for (int j=0; j<w; j++) {
            d[i][j] = INF;
            visited[i][j] = (s[j] == '#');
        }
    }
    deque<P> dq;
    dq.push_back(start);
    d[start.fi][start.se] = 0;
    while (!dq.empty()) {
        P f = dq.front(); dq.pop_front();
        if (visited[f.fi][f.se]) continue;
        visited[f.fi][f.se] = true;
        for (int i=f.fi-1; i<=f.fi+1; i++) {
            for (int j=f.se-1; j<=f.se+1; j++) {
                if (i != f.fi && j != f.se) continue;
                if (in_range(P{i, j}, h, w) && !visited[i][j] && d[i][j] > d[f.fi][f.se]) {
                    dq.push_front(P{i, j});
                    d[i][j] = d[f.fi][f.se];
                }
            }
        }
        for (int i=f.fi-2; i<=f.fi+2; i++) {
            for (int j=f.se-2; j<=f.se+2; j++) {
                if (in_range(P{i, j}, h, w) && !visited[i][j] && d[i][j] > d[f.fi][f.se] + 1) {
                    dq.push_back(P{i, j});
                    d[i][j] = d[f.fi][f.se] + 1;
                }
            }
        }
    }
    cout << (d[goal.fi][goal.se] < INF ? d[goal.fi][goal.se] : -1) << '\n';
    return 0;
}