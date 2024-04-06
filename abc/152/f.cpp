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

vector<P> G[51]; // 行先, id
bool visited[51] = {0};
int edges[51] = {0};

bool dfs(int i, int to, int id) {
    visited[i] = true;
    if (i == to) 
        return true;
    for (auto &g:G[i]) {
        if (visited[g.fi]) continue;
        int d = dfs(g.fi, to, id);
        if (d) {
            edges[g.se] |= (1 << id); // 辺g.seによって条件idが成立する
            return true;
        }
    }
    return false;
}

ll dp[51][(1 << 20) + 1];

int main() {
    int n, m;
    cin >> n;
    for (int i=0, ai, bi; i<n-1; i++) {
        cin >> ai >> bi;
        ai--; bi--;
        G[ai].push_back({bi, i});
        G[bi].push_back({ai, i});
    }
    cin >> m;
    for (int i=0, ui, vi; i<m; i++) {
        cin >> ui >> vi;
        ui--; vi--;
        fill(visited, visited+n, false);
        dfs(ui, vi, i);
    }
    fill(dp[0], dp[n], 0);
    dp[0][0] = 1;
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<(1<<m); j++)
            dp[i+1][j] = dp[i][j];
        for (int j=0; j<(1 << m); j++) {
            dp[i+1][j | edges[i]] += dp[i][j];
        }
    }
    cout << dp[n-1][(1 << m) - 1] << '\n';
    return 0;
}