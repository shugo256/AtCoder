#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

using P = pair<long, int>;

#define MAX_N 1000010
// トポロジカルソートしつつ閉路検出 O(V+E)
vector<int> G[MAX_N], // 隣接行列
            torder;   // トポロジカル順序の格納先
int ins[MAX_N] = {0}, // 各ノードの入次数
    d[MAX_N]   = {0}; // 根ノードからの最大距離、これの最大値がDAGの最大距離

// DAG(ループなし)なら最大距離を、ループありなら-1を返す
// Gとinsを入力から作っておいて、torderとdにこの関数で書き込む
// nは頂点の数
int topological_sort(int n) {
    int cnt = 0, ans = 0;
    queue<int> zeros;
    for (int i=0; i<n; i++)
        if (ins[i] == 0) {
            zeros.push(i);
            cnt++;
        }
    while (!zeros.empty()) {
        int v = zeros.front(); zeros.pop();
        torder.push_back(v);
        for (auto g:G[v]) {
            ins[g]--; // v->gの辺を消す
            d[g] = max(d[g], d[v]+1);
            ans  = max(ans,  d[g]);
            if (ins[g] == 0) {
                zeros.push(g);
                cnt++; // 訪問した頂点をカウント、閉路がある場合訪れない点ができる
            }
        }
    }
    if (cnt < n) return -1;
    else return ans;
}

int main() {
    int n;
    cin >> n;
    int zip[n][n], cnt=0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            zip[i][j] = zip[j][i] = cnt;
            cnt++;
        }
    }
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        a--;
        int prev = zip[i][a];
        for (int j=0; j<n-2; j++) {
            cin >> a;
            a--;
            G[prev].push_back(zip[i][a]);
            prev = zip[i][a];
            ins[prev]++;
        }
    }
    fill(d, d+cnt, 1);
    cout << topological_sort(cnt) << '\n';
    return 0;
}