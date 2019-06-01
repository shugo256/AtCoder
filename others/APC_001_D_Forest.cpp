#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAX_N 100010

using namespace std;

typedef priority_queue<long, vector<long>, greater<long>> minpq; 

long a[MAX_N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];
    vector<int> G[n];
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    if (n - 1 - m == 0) {
        cout << 0 << '\n';
        return 0;
    } else if (2 * (n - 1 - m) > n) {
        cout << "Impossible" << '\n';
        return 0;
    }
    bool used[MAX_N] = {0}, visited[MAX_N] = {0};
    long ans=0;
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            int best=i;
            queue<int> bfs;
            bfs.push(i);
            while (!bfs.empty()) {
                int now = bfs.front(); bfs.pop();
                visited[now] = true;
                if (a[now] < a[best]) best = now;
                for (auto g:G[now]) {
                    if (visited[g]) continue;
                    bfs.push(g);
                }
            }
            used[best] = true;
            ans += a[best];
        }
    }
    minpq pq;
    for (int i=0; i<n; i++) {
        if (used[i]) continue;
        pq.push(a[i]);
    }
    int cnt = n - m - 1, remain = cnt * 2 - cnt - 1;
    for (int i=0; i<remain; i++) {
        ans += pq.top(); pq.pop();
    }
    cout << ans << '\n';
    return 0;
}