#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAX_N 100010

using namespace std;

typedef priority_queue<long,vector<long>,greater<long>> minpq;

long a[MAX_N];

struct uftree {
    int par[MAX_N], rank[MAX_N], minid[MAX_N]; //その集合のうちa[i]を最小にするi;
    uftree(int N) {
        for (int i=0; i<N; i++) {
            par[i] = i;
            rank[i] = 0;
            minid[i] = i;
        }
    }
    int root(int x) {
        return par[x] == x ? x : par[x] = root(par[x]); // 高速化ポイント
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (rank[x] > rank[y]) par[y] = x;
        else {
            par[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        }
        // cerr << x << ' ' << y << ' ' << minid[x] << ' ' << minid[y] << '\n';
        if (a[minid[x]] < a[minid[y]]) minid[y] = minid[x];
        else minid[x] = minid[y];
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int get_minid(int x) {
        return minid[root(x)];
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];
    uftree uft(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        uft.unite(x, y);
    }
    bool used[MAX_N] = {0};
    for (int i=0; i<n; i++) used[uft.get_minid(i)] = true;
    int cnt=0, ans=0;
    minpq pq;
    for (int i=0; i<n; i++) {
        // cerr << i << ' ' << used[i] << '\n';
        if (used[i]) {
            cnt++;
            ans += a[i];
        } else {
            pq.push(a[i]);
        }
    }
    if (cnt == 1) {
        cout << 0 << "\n";
        return 0;
    } else if (cnt * 2 > n) {
        cout << "Impossible" << '\n';
        return 0;
    }
    int remain = (cnt-1) * 2 - cnt;
    for (int i=0; i<remain; i++) {
        ans += pq.top(); pq.pop();
    }
    cout << ans << '\n';
    return 0;
}