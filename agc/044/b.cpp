#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

int main() {
    int n;
    cin >> n;
    vector seats(n+2, vector(n+2, false));
    vector dist(n+2, vector(n+2, 0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            seats[i][j] = true;
            dist[i][j] = min({i, j, n+1-i, n+1-j});
        }
    }
    vector<P> leave;
    for (int i=0, pi; i<n*n; i++) {
        cin >> pi;
        pi--;
        leave.push_back({pi / n + 1, pi % n + 1});
    }
    int ans = 0;
    for (auto &li:leave) {
        seats[li.fi][li.se] = false;
        dist[li.fi][li.se]--;
        ans += dist[li.fi][li.se];
        deque<P> dq;
        dq.push_back(li);
        while (!dq.empty()) {
            P f = dq.front(); dq.pop_front();
            for (int x=max(f.fi-1, 0); x<=min(f.fi+1, n+1); x++) {
                for (int y=max(f.se-1, 0); y<=min(f.se+1, n+1); y++) {
                    if (x != f.fi && y != f.se) continue;
                    if (seats[x][y] && dist[x][y] > dist[f.fi][f.se] + 1) {
                        dist[x][y] = dist[f.fi][f.se] + 1;
                        dq.push_back({x, y});
                    } 
                    if (!seats[x][y] && dist[x][y] > dist[f.fi][f.se]) {
                        dist[x][y] = dist[f.fi][f.se];
                        dq.push_front({x, y});
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}