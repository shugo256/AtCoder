#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define MAX 200010

vector<int> G[MAX];
int a[MAX] = {0};
int d[MAX];

void dfs(int i, int par, vector<int> &lis) {
    bool push = false;
    int id, val;
    auto pp = partition_point(lis.begin(), lis.end(), [&](int x) {
        return x < a[i];
    });
    if (pp == lis.end()) {
        push = true;
        lis.push_back(a[i]);
    } else {
        id = pp - lis.begin();
        val = *pp;
        *pp = a[i];
    }
    d[i] = lis.size();
    for (auto &g:G[i]) {
        if (g == par) continue;
        dfs(g, i, lis);
    }
    if (push) {
        lis.pop_back();
    } else {
        lis[id] = val;
    }
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
    vector<int> lis;
    dfs(0, -1, lis);
    for (int i=0; i<n; i++) {
        cout << d[i] << '\n';
    }
    return 0;
}