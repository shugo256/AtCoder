#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define MAX_N 310
#define INF 1000000000000000

using P = pair<long, long>;
#define fi first
#define se second

long L;
int n, m;

// 全対全の距離を求める N^3
long d[MAX_N][MAX_N]; // i->jのコスト あらかじめINF初期化してから入力を反映させる
void warshall_floyd() { 
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
    cin >> n >> m >> L;
    fill(d[0], d[n], INF);
    for (int i=0, a, b; i<m; i++) {
        long c;
        cin >> a >> b >> c;
        a--; b--;
        d[a][b] = d[b][a] = c;
    }
    warshall_floyd();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            d[i][j] = (d[i][j] > L ? INF : 1);
        }
    }
    warshall_floyd();
    int q; cin >> q;
    for (int i=0, s, t; i<q; i++) {
        cin >> s >> t;
        s--; t--;
        cout << (d[s][t] < INF ? d[s][t] - 1 : -1) << '\n';
    }
    return 0;
}