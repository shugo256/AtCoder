#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define MAX_N 410

// 全対全の距離を求める N^3
int n;
int d[MAX_N][MAX_N]; // i->jのコスト あらかじめINF初期化してから入力を反映させる
void warshall_floyd() { 
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

using P = pair<int, int>;
#define fi first
#define se second

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

int main() {
    int h, w;
    cin >> h >> w;
    vector<P> roads;
    for (int i=0; i<h; i++) {
        string s;
        cin >> s;
        for (int j=0; j<w; j++) {
            if (s[j] == '.') roads.push_back(P{i, j});
        }
    }
    map<P, int> zip;
    vector<P> unzip;
    int m = compress(roads, zip, unzip);
    n = m;
    fill(d[0], d[MAX_N], MAX_N);
    for (int i=0; i<m; i++) d[i][i] = 0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (!zip.count(P{i, j})) continue;
            int x = zip[P{i, j}], y;
            if (zip.count(P{i, j+1})) {
                y = zip[P{i, j+1}];
                d[x][y] = 1;
            }
            if (zip.count(P{i, j-1})) {
                y = zip[P{i, j-1}];
                d[x][y] = 1;
            }
            if (zip.count(P{i+1, j})) {
                y = zip[P{i+1, j}];
                d[x][y] = 1;
            }
            if (zip.count(P{i-1, j})) {
                y = zip[P{i-1, j}];
                d[x][y] = 1;
            }
        }
    }
    warshall_floyd();
    int ans = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<i; j++) {
            ans = max(ans, d[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}