#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

int to_node(map<P, int> &mp, int x, int y) {
    if (!mp.count({x, y})) mp[{x, y}] = mp.size();
    return mp[{x, y}];
}

// Ford-Fulkerson法用名前空間(使いたかっただけ)
/*
 * 最大流量をF, 辺の数をMとして O(FM)
 * だが、蟻本曰くこんなにかかることはまずなく、一見危なそうでも意外と大丈夫らしい
 */

namespace FordFulkerson {
    const int MAX_N = 5010;
    const ll INF = 10000000000000;

    struct edge {
        int to;
        ll cap;
        int rev; // 行先, 容量, 逆辺
    };
    int timestamp = 0;

    int used[MAX_N];
    vector<edge> G[MAX_N];

    // 辺の追加、ちょいめんどいので関数
    // f -> tに向かう流量がcr以上、c以下となるエッジを追加
    // 無向グラフの場合は directed = falseとする
    void add_edge(int f, int t, int c=0, bool directed=true) {
        G[f].push_back({t, c, (int)G[t].size()});
        G[t].push_back({f, (directed ? 0 : c), (int)G[f].size() - 1});
    }
    
    // 今の頂点v, ゴールt, vに流せる最大流量flow
    // 返り値dは最終的に流した流量
    ll dfs(int v, int t, ll flow) {
        used[v] = timestamp;
        if (v == t) return flow;
        for (auto &g:G[v]) {
            if (used[g.to] != timestamp && g.cap > 0) {
                ll d = dfs(g.to, t, min(flow, g.cap));
                if (d > 0) {
                    // 容量の更新
                    g.cap -= d;
                    G[g.to][(size_t)g.rev].cap += d;
                    return d;
                }
            }
        }
        return 0; // どこにも流せなければ0
    }

    ll max_flow(int s, int t) {
        ll flow = 0;
        fill(begin(used), end(used), -1);
        for (ll f; (f = dfs(s, t, INF)) > 0; timestamp++) {
            flow += f;
        }
        return flow;
    }
}

#define START 5000
#define GOAL 5001

int main() {
    int m, n;
    cin >> m >> n;
    int a[m][n], b[m][n];
    map<P, int> mp;
    for (auto &ai:a) for (auto &aij:ai) cin >> aij;
    int cnt = 0;
    for (int i=0; i<m; i++) for (int j=0; j<n; j++) {
        cin >> b[i][j];
        if (a[i][j] == b[i][j]) continue;
        cnt++;
        int me = to_node(mp, i, j);
        if ((i + j) % 2) {
            FordFulkerson::add_edge(me, GOAL, 1);
            if (i > 0 && a[i][j] != a[i-1][j] && mp.count({i-1, j})) {
                int up = mp[{i-1, j}];
                FordFulkerson::add_edge(up, me, 1);
            }
            if (j > 0 && a[i][j] != a[i][j-1] && mp.count({i, j-1})) {
                int left = mp[{i, j-1}];
                FordFulkerson::add_edge(left, me, 1);
            }
        } else {
            FordFulkerson::add_edge(START, me, 1);
            if (i > 0 && a[i][j] != a[i-1][j] && mp.count({i-1, j})) {
                int up = mp[{i-1, j}];
                FordFulkerson::add_edge(me, up, 1);
            }
            if (j > 0 && a[i][j] != a[i][j-1] && mp.count({i, j-1})) {
                int left = mp[{i, j-1}];
                FordFulkerson::add_edge(me, left, 1);
            }
        }
    }
    int pair = FordFulkerson::max_flow(START, GOAL);
    cout << cnt - pair << '\n';
    return 0;
}