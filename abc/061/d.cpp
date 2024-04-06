#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_N 1010
#define INF 10000000000000

using namespace std;

int n, m;
long d[MAX_N];
bool negative[MAX_N];
struct edge { long from, to, cost; };
vector<edge> edges; // 長さM
// ベルマンフォード法でstartから各点までの最短距離を計算する O(MN)
// checkLoop=trueかつ負のループがある場合は負のループにより最短距離が
// -INFになってしまう点を検出し、negativeに格納
void bellmanFord(int start, bool checkLoop=false) {
    fill(d, d+n, INF);
    fill(negative, negative + n, false);
    d[start] = 0;
    bool negloop = false;
    for (int i=1; i<n; i++) {
        for (auto e : edges) {
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                if (i == n-1) negloop = true;
            }
        }
    }
    if (!checkLoop || !negloop) return;
    for (int i = 0; i < n; i++) {
        for (auto e : edges) {
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                negative[e.to] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edges.push_back({a, b, -c});
    }
    bellmanFord(0, true);
    if (negative[n-1]) cout << "inf" << '\n';
    else cout << -d[n-1] << '\n';
    return 0;
}