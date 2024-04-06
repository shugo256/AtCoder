#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

vector<int> G[100010];
bool visited[100010]={0};

int grundy(int i=0) {
    int ans = 0;
    visited[i] = true;
    for (auto g:G[i]) {
        if (visited[g]) continue;
        ans ^= grundy(g);
    }
    if (i > 0) ans++;
    // cerr << i << ' ' << ans << '\n';
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i=1, x, y; i<n; i++) {
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cout << (grundy() ? "Alice" : "Bob") << '\n';
    return 0;
}