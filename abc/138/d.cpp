#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

long rui[200010]={0};
bool visited[200010]={0};
vector<int> G[200010];

void dfs(int i=0, long val=0) {
    cerr << i << endl;
    visited[i] = true;
    rui[i] += val;
    for (auto g:G[i]) {
        if (visited[g]) continue;
        dfs(g, rui[i]);
    }
    return;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i=0; i<q; i++) {
        long p, x;
        cin >> p >> x;
        rui[p-1] += x;
    }
    dfs();
    for (int i=0; i<n; i++)
        cout << rui[i] << (i < n-1 ? ' ' : '\n');
    return 0;
}