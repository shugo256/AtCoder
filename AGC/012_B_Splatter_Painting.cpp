#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

struct query { int v, d, c; };

int main() {
    int n, m, q;
    cin >> n >> m;
    vector<int> G[n];
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cin >> q;
    vector<query> ques;
    for (int i=0; i<q; i++) {
        int v, d, c;
        cin >> v >> d >> c;
        ques.push_back({v-1, d, c});
    }
    reverse(ques.begin(), ques.end());
    int dist[n], color[n];
    fill(dist, dist+n, -1);
    fill(color, color+n, 0);
    queue<query> qq;
    for (auto que:ques) {
        qq.push(que);
        while (!qq.empty()) {
            query f = qq.front(); qq.pop();
            if (color[f.v] == 0) color[f.v] = f.c;
            for (auto g:G[f.v]) {
                if (f.d - 1 <= dist[g]) continue;
                dist[g] = f.d - 1;
                qq.push({g, f.d-1, f.c});
            }
        }
    }
    for (auto c:color) cout << c << '\n';
    return 0;
}