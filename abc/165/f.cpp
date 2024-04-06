#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define MAX 200010
#define INF (int)(1e9 + 10)

vector<int> G[MAX];
int a[MAX] = {0};
int d[MAX];

void dfs(int i, int par, vector<int> &lis) {
    bool push = false;
    auto pp_update = partition_point(lis.begin(), lis.end(), [&](int x) {
        return x < a[i];
    });
    int org = *pp_update;
    *pp_update = a[i];
    auto pp_end = partition_point(lis.begin(), lis.end(), [&](int x) {
        return x < INF;
    });
    d[i] = pp_end - lis.begin() - 1;
    for (auto &g:G[i]) {
        if (g == par) continue;
        dfs(g, i, lis);
    }
    *pp_update = org;
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0, ui, vi; i<n-1; i++) {
        cin >> ui >> vi;
        ui--; vi--;
        G[ui].push_back(vi);
        G[vi].push_back(ui);
    }
    vector<int> lis(n+1, INF);
    lis[0] = -INF;
    dfs(0, -1, lis);
    for (int i=0; i<n; i++) {
        cout << d[i] << '\n';
    }
    return 0;
}