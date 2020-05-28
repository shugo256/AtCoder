#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#include <map>
#include <set>
// vecのなかの全要素について座標圧縮を行い、元座標->圧縮後座標というmapを作る
// O(NlogN) 座圧後のサイズを返す
// org: もともとの各iに対する座標 値渡しなので破壊しません
// zip: 圧縮
// unzip: 復元
template <typename T>
int compress(vector<T> org, map<T, int> &zip, vector<T> &unzip) {
    sort(org.begin(), org.end()); 
    org.erase(unique(org.begin(), org.end()), org.end()); // vecの各要素を小さい順に重複を無くして並べたもの
    int i = 0;
    for (auto &oi : org) {
        zip[oi] = i;
        unzip.push_back(oi);
        i++;
    }
    return i;
}

#define amin(a, b) a = min(a, b)
#define amax(a, b) a = max(a, b)

struct line {ll a, b, c;};

using P = pair<int, int>;
#define fi first
#define se second

int main() {
    int n, m;
    cin >> n >> m;
    line tate[n], yoko[m];
    vector<ll> torg(1, 0), yorg(1, 0), tunzip, yunzip;
    for (auto &ti:tate) {
        cin >> ti.a >> ti.b >> ti.c;
        torg.push_back(ti.a);
        torg.push_back(ti.b);
        yorg.push_back(ti.c);
    }

    for (auto &yi:yoko) {
        cin >> yi.c >> yi.a >> yi.b;
        yorg.push_back(yi.a);
        yorg.push_back(yi.b);
        torg.push_back(yi.c);
    }
    map<ll, int> tzip, yzip;
    int tk = compress(torg, tzip, tunzip);
    int yk = compress(yorg, yzip, yunzip);
    vector<P> tatel[yk];
    vector<P> yokol[tk];
    for (auto &ti:tate) {
        tatel[yzip[ti.c]].push_back(P{tzip[ti.a], tzip[ti.b]});
    }
    for (auto &yi:yoko) {
        yokol[tzip[yi.c]].push_back(P{yzip[yi.a], yzip[yi.b]});
    }
    vector grid(2*tk+1, vector(2*yk+1, 0ll));
    for (int i=0; i<tk; i++) {
        sort(yokol[i].begin(), yokol[i].end());
        int j = 0;
        for (auto &yi:yokol[i]) {
            for (j = max(j, 2*yi.fi+1); j <= 2*yi.se+1; j++) {
                grid[2*i + 1][j] = -1;
            }
        }
    }
    for (int j=0; j<yk; j++) {
        sort(tatel[j].begin(), tatel[j].end());
        int i = 0;
        for (auto &ti:tatel[j]) {
            for (i = max(i, 2*ti.fi+1); i <= 2*ti.se+1; i++) {
                grid[i][2*j + 1] = -1;
            }
        }
    }
    for (int i=0; i<2*tk+1; i++) {
        for (int j=0; j<2*yk+1; j++) {
            if (i == 0 || j == 0 || i == 2 * tk || j == 2 * yk) {
                grid[i][j] = -2;
            } else if (i % 2 == 0 && j % 2 == 0) {
                grid[i][j] = (tunzip[i / 2] - tunzip[i / 2 - 1]) * (yunzip[j / 2] - yunzip[j / 2 - 1]);
            }
        }
    }
    queue<P> q;
    q.push({2*tzip[0]+1, 2*yzip[0]+1});
    grid[2*yzip[0]+1][2*tzip[0]+1] = -1;
    ll ans = 0;
    while (!q.empty()) {
        P f = q.front(); q.pop();
        for (int x=max(f.fi-1, 0); x<=min(f.fi+1, 2*tk); x++) {
            for (int y=max(f.se-1, 0); y<=min(f.se+1, 2*yk); y++) {
                if (x != f.fi && y != f.se) continue;
                if (grid[x][y] == -1) continue;
                if (grid[x][y] == -2) {
                    cout << "INF" << '\n';
                    return 0;
                }
                ans += grid[x][y];
                grid[x][y] = -1;
                q.push({x, y});
            }
        }
    }
    cout << ans << '\n';
    return 0;
}