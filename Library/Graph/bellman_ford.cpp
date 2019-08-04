int n, m;
long d[MAX_N];
bool negative[MAX_N];
struct edge {
    long from, to, cost;
};
vector<edge> edges;  // 長さM
// ベルマンフォード法でstartから各点までの最短距離を計算する O(MN)
// checkLoop=trueかつ負のループがある場合は負のループにより最短距離が
// -INFになってしまう点を検出し、negativeに格納
// 要するにnegativeは負のループと繋がってる部分がtrueになる
void bellmanFord(int start, bool checkLoop = false) {
    fill(d, d + n, INF);
    fill(negative, negative + n, false);
    d[start] = 0;
    bool negloop = false;
    for (int i = 1; i < n; i++) {
        for (auto e : edges) {
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                if (i == n - 1) negloop = true;
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