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

#define MAX_L 100010
#define MAX_N 262145
#define MAX_W 1000010

#define amax(a, b) a = max(a, b);

vector<P> qs[MAX_N];
int ans[MAX_N], v[MAX_N], w[MAX_N];

struct query {
    int lim, sum, id;
}

void dfs(int i, int n, vector<query> &dp, int d, vector<int> &pars) {
    pars.push_back(i);
    if (i * 2 <= n) dfs(i * 2, n, dp, d + 1, pars);
    if (i * 2 + 1 <= n) dfs(i * 2 + 1, n, dp, d + 1, pars);
    pars.pop_back();
    if (d < 9) {
        set<int> weights;
        for (int i=0; i<(1 << d); i++) {
            int sum = 0;
            for (int j=0; j<d; j++) {
                if (i & (1 << j)) {
                    sum += w[pars[j]];
                }
            }
            weights.insert(sum);
        }
        weights.insert(MAX_W);
        set<P> 
    }
}

int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> v[i] >> w[i];
    }
    int q; cin >> q;
    for (int i=1, vi, li; i<=q; i++) {
        cin >> vi >> li;
        qs[vi].push_back({i, li});
    }
    vector dp(1, vector<int>(MAX_L, 0));
    dfs(1, n, dp);
    for (int i=1; i<=q; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}