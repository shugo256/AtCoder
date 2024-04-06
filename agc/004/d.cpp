#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define MAX_N 100010

vector<int> G[MAX_N];
int ans = 0, n, k;

int dfs(int i=0) {
    int h = 0;
    for (auto g:G[i]) {
        int d = dfs(g) + 1;
        if (d == k && i > 0) {
            ans++;
            d = 0;
        }
        h = max(h, d);
    }
    return h;
}

int main() {
    int a0;
    cin >> n >> k >> a0;
    if (a0 != 1) ans++;
    for (int i=1; i<n; i++) {
        int j; cin >> j;
        j--;
        G[j].push_back(i);
    }
    dfs();
    cout << ans << '\n';
    return 0;
}