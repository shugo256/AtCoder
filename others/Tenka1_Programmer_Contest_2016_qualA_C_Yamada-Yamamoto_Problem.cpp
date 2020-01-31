#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define MAX_N 26
// トポロジカルソートしつつ閉路検出 O(V+E)
vector<int> G[MAX_N]; // 隣接行列
string torder;   // トポロジカル順序の格納先
int ins[MAX_N] = {0}, // 各ノードの入次数
    d[MAX_N]   = {0}; // 根ノードからの最大距離、これの最大値がDAGの最大距離

// DAG(ループなし)なら最大距離を、ループありなら-1を返す
// Gとinsを入力から作っておいて、torderとdにこの関数で書き込む
// nは頂点の数
int topological_sort(int n) {
    int cnt = 0, ans = 0;
    priority_queue<int, vector<int>, greater<int>> zeros;
    for (int i=0; i<n; i++)
        if (ins[i] == 0) {
            zeros.push(i);
            cnt++;
        }
    while (!zeros.empty()) {
        int v = zeros.top(); zeros.pop();
        torder += (char)('a' + v);
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
    for (int i=0; i<n; i++) {
        string a, b;
        cin >> a >> b;
        int dif = 0, minlen = min(a.size(), b.size());
        for ( ; dif < minlen; dif++)
            if (a[dif] != b[dif])
                break;
        if (dif == minlen) {
            if (a > b) {
                cout << -1 << '\n';
                return 0;
            }
            else
                continue;
        }
        G[a[dif] - 'a'].push_back(b[dif] - 'a');
        ins[b[dif] - 'a']++;
    }
    if (topological_sort(26) < 0) cout << -1 << endl;
    else cout << torder << '\n';
    return 0;
}