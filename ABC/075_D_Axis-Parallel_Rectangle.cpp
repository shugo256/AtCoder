#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    map<long, int> zatsu;
    vector<pair<long, long>> points;
    for (int i=0; i<n; i++) {
        long x, y;
        cin >> x >> y;
        zatsu[x] = zatsu[y] = 1;
        points.push_back({x, y});
    }
    int cnt = 0;
    vector<long> zinv(1, 0);
    for (auto &z:zatsu) {
        z.second = ++cnt;
        zinv.push_back(z.first);
    }
    int rui[105][105] = {{0}};
    for (auto &p:points)
        rui[zatsu[p.first]][zatsu[p.second]] = 1;
    for (int i=1; i<=cnt; i++)
        for (int j=1; j<=cnt; j++)
            rui[i][j] += rui[i-1][j] + rui[i][j-1] - rui[i-1][j-1];
    long ans = LONG_MAX;
    for (int xi=1; xi<=cnt; xi++) {
        for (int yi=1; yi<=cnt; yi++) {
            for (int xj=xi; xj<=cnt; xj++) {
                for (int yj=yi; yj<=cnt; yj++) {
                    int inside = rui[xi-1][yi-1] + rui[xj][yj] - rui[xi-1][yj] - rui[xj][yi-1];
                    if (inside >= k)
                        ans = min(ans, (zinv[xj] - zinv[xi]) * (zinv[yj] - zinv[yi]));
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}