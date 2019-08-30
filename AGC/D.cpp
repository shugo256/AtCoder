#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n, m;
int a[101][101],
    b[101][101]; // n m
bool open[101][101], // m n i列目で商がjとなるものをまだ使っていないかどうか
     used[101]; // m
bool dfs(int i=0, int j=0) {
    if (i == n) return true;
    else if (j == m) return dfs(i+1, 0);
    else {
        if (j == 0) fill(used, used + m, false);
        for (int k=0; k<m; k++) {
            if (used[k]) continue;
            if (open[i][a[i][k] / m]) {
                open[i][a[i][k] / m] = false;
                if (dfs(i, j+1)) {
                    b[i][j] = a[i][k];
                    return true;
                }
                open[i][a[i][k] / m] = true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (auto &ai:a) {
        for (auto &aij:ai) {
            cin >> aij;
        } 
    }
    fill(open[0], open[m], true);
    dfs();
    for (auto &bi:b) {
        for (auto &bij:bi) {
            cout << bij << ' ';
        }
        cout << '\0' << '\n';
    }
    return 0;
}