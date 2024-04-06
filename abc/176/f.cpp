#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

#define amax(a, b) a = max(a, b)

#define INF 10000000

using P = pair<int, int>;
#define fi first
#define se second

void update(int x, int y, int val, vector<vector<int>> &dp, vector<int> &row, int &best) {
    amax(dp[x][y], val);
    amax(dp[y][x], val);
    amax(row[x], val);
    amax(row[y], val);
    amax(best, val);
}

int main() {
    int n, a0, a1;
    cin >> n >> a0 >> a1;
    a0--; a1--;
    vector dp(n, vector(n, -INF));
    vector row(n, -INF);
    int best = -INF, offset = 0;
    update(a0, a1, 0, dp, row, best);
    for (int i=0, ax, ay, az; i<n-1; i++) {
        cin >> ax >> ay >> az;
        ax--; ay--; az--;

        map<int, int> cnt;
        cnt[ax]++; cnt[ay]++; cnt[az]++;

        int prev_best = best;
        vector prev_row(row);

        if (cnt.size() == 3) {
            offset++;
        } else if (cnt.size() == 2) {
            auto itr = cnt.begin();
            P p2 = *itr, p1 = *(++itr);
            if (p2.fi == 1) swap(p2, p1);
            vector prev_dp(dp[p2.fi]);
            for (int i=0; i<n; i++) {
                update(p1.fi, i, prev_dp[i]+1, dp, row, best);
                update(p1.fi, i, prev_row[i], dp, row, best);
                update(p2.fi, i, prev_row[i], dp, row, best);
            }
            update(p1.fi, p2.fi, best, dp, row, best);
        } else {
            for (int i=0; i<n; i++) {
                update(ax, i, prev_row[i], dp, row, best);
                update(ay, i, prev_row[i], dp, row, best);
                update(az, i, prev_row[i], dp, row, best);
            }
            update(ax, ay, prev_best, dp, row, best);
            update(ay, az, prev_best, dp, row, best);
            update(az, ax, prev_best, dp, row, best);
        }
    }
    int alast; cin >> alast;
    amax(best, dp[alast][alast]+1);
    cout << best + offset << '\n';
    return 0;
}