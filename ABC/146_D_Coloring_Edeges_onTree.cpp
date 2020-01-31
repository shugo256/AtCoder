#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

struct edge {int to, i;};
vector<edge> G[100010];

int color[100010];

int dfs(int i=0, int p=-1, int c=-1) {
    int cnt = 1, maxc = 0;
    for (auto g:G[i]) {
        if (g.to == p) continue;
        if (cnt == c) cnt++;
        maxc = max(maxc, dfs(g.to, i, cnt));
        color[g.i] = cnt;
        cnt++;
    }
    return max(maxc, cnt-1);
}

int main() {
    int n;
    cin >> n;
    for (int i=0, a, b; i<n-1; i++) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }
    cout << dfs() << '\n';
    for (int i=0; i<n-1; i++) {
        cout << color[i] << '\n';
    }
    return 0;
}