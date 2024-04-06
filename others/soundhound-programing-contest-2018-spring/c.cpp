#include <iostream>
#include <algorithm>

using namespace std;

bool map[42][42] = {{0}};

void dfs_r(int x, int y, int *cnt, bool color) {
    if (!map[x][y]) return;
    map[x][y] = false;
    cnt[color]++;
    color = !color;
    dfs_r(x+1, y, cnt, color);
    dfs_r(x-1, y, cnt, color);
    dfs_r(x, y+1, cnt, color);
    dfs_r(x, y-1, cnt, color);
}

int dfs(int x, int y) {
    int cnt[2] = {0};
    dfs_r(x, y, cnt, 0);
    cerr << cnt[0] << ' ' << cnt[1] << endl;
    return max(cnt[0], cnt[1]);
}



int main() {
    int r, c;
    cin >> r >> c;
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            char cij; cin >> cij;
            map[i][j] = (cij == '.'); 
        }
    }
    int sum = 0;
    for (int i=1; i<=r; i++)
        for (int j=1; j<=c; j++)
            sum += dfs(i, j);
    cout << sum << '\n';
    return 0;
}