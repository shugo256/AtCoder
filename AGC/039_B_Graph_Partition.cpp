#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define MAX_N 210
#define INF 100000

// 全対全の距離を求める N^3
int n;
long d[MAX_N][MAX_N]; // i->jのコスト あらかじめINF初期化してから入力を反映させる
long ans=0;
void warshall_floyd() { 
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                if (k == n-1 && d[i][j] < INF)
                    ans = max(ans, d[i][j]);
            }
}

vector<int> G[201];
bool color[201], visited[201]={0};
bool dfs(int i=0, bool c=true) {
    color[i] = c;
    visited[i] = true;
    for (auto g:G[i]) {
        if ((!visited[g] && !dfs(g, !c)) || color[g] == c) 
            return false;
    }
    return true;
}

int main() {
    cin >> n;
    string s;
    for (int i=0; i<n; i++) {
        cin >> s;
        for (int j=0; j<n; j++) {
            if (i == j) {
                d[i][i] = 0;
                continue;
            }
            if (s[j] == '1') {
                d[i][j] = 1;
                G[i].push_back(j);
            }
            else d[i][j] = INF;
        }
    }
    if (!dfs()) {
        cout << -1 << '\n';
        return 0;
    }
    warshall_floyd();
    cout << ans + 1 << '\n';
    return 0;
}