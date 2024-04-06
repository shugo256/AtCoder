#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

int main() {
    map<int, P> m;
    bool bingo[3][3] = {{0}};
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            int a;
            cin >> a;
            m[a] = {i, j};
        }
    }
    int n;
    cin >> n;
    for (int i=0, b; i<n; i++) {
        cin >> b;
        if (m.count(b)) bingo[m[b].fi][m[b].se] = true;
    }
    int row[3] = {0}, col[3] = {0}, xl = 0, xr = 0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (!bingo[i][j]) continue;
            if (++row[i] == 3 || ++col[j] == 3 || (i == j && ++xl == 3) || (i + j == 2 && ++xr == 3)) {
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}