#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define MAX 100010
#define INF 100000000

bool visited[MAX] = {0};
vector<int> G[MAX];
int high[MAX], low[MAX], ans[MAX];

bool dfs(int i, int a) {
    //cerr << i << ' ' << low[i] << ' ' << high[i] << ' ' << a << '\n';
    ans[i] = a;
    visited[i] = true;  
    for (auto g:G[i]) {
        if (visited[g]) continue;
        if (low[g] <= a-1 && a-1 <= high[g]) {
            if (!dfs(g, a-1)) {
                return false;
            }
        }
        else if (low[g] <= a+1 && a+1 <= high[g]) {
            if (!dfs(g, a+1)) {
                return false;
            }
        }
        else
            return false;
    }
    return true;
}

struct node {int v, p;};

int main() {
    int n;
    cin >> n;
    for (int i=0, a, b; i<n-1; i++) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int k;
    cin >> k;
    int v, p;
    queue<node> qh, ql;
    fill(high, high+n, INF);
    fill(low, low+n, -INF);
    for (int i=0; i<k; i++) {
        cin >> v >> p;
        v--;
        high[v] = low[v] = p;
        qh.push(node{v, p});
        ql.push(node{v, p});
    }
    while (!qh.empty()) {
        node f = qh.front(); qh.pop();
        for (auto g:G[f.v]) {
            if (high[g] > f.p + 1) {
                high[g] = f.p + 1;
                qh.push(node{g, high[g]});
            }
        }
    }
    while (!ql.empty()) {
        node f = ql.front(); ql.pop();
        for (auto g:G[f.v]) {
            if (low[g] < f.p - 1) {
                low[g] = f.p - 1;
                ql.push(node{g, low[g]});
            }
        }
    }
    fill(ans, ans+n, -1);
    visited[v] = true;
    if (dfs(v, p)) {
        cout << "Yes" << '\n';
        for (int i=0; i<n; i++) cout << ans[i] << '\n';
    } else {
        cout << "No" << '\n';
    }
    return 0;
}