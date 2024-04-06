#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

#define INF 1000000000

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int max_k = min(h, w);
    bool field[h][w];
    fill(field[0], field[h], true);
    for (int i=0, a, b; i<n; i++) {
        cin >> a >> b;
        field[a-1][b-1] = false;
    }
    int up[h][w], down[h][w], prev;
    for (int j=0; j<w; j++) {
        prev = 0;
        for (int i=0; i<h; i++) {
            prev *= field[i][j];
            prev += field[i][j];
            up[i][j] = prev;
        }
        prev = 0;
        for (int i=h-1; i>=0; i--) {
            prev *= field[i][j];
            prev += field[i][j];
            down[i][j] = prev;
        }
    }
    vector<P> lines;
    lines.emplace_back(-1, -1);
    for (int d=-h+1; d<w; d++) {
        int x = (d > 0 ? 0 : -d),
            y = (d > 0 ? d : 0);
        for ( ; x < h && y < w; (x++, y++)) {
            if (field[x][y]) {
                lines.emplace_back(x, y);
            }
            else {
                lines.emplace_back(-1, -1);
            }
        }
        lines.emplace_back(-1, -1);
    }
    int ans = 0, k;
    set<P> s;
    for (auto &p:lines) {
        if (p.fi == -1) {
            s.clear();
            k=0;
            continue;
        }
        int u = up[p.fi][p.se],
            d = down[p.fi][p.se];
        s.insert({k, k + d - 1});
        auto itr = s.lower_bound({k-u, INF});
        while (itr != s.end() && itr->se < k) itr = s.erase(itr);
        if (itr != s.end()) ans = max(ans, k - itr->fi + 1);
        k++;
    }
    cout << ans << '\n';
    return 0;
}