#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    int cnt=1; 
    string s[h];
    int ans[h][w];
    bool aru[h];
    fill(aru, aru+h, false);
    for (int i=0; i<h; i++) {
        cin >> s[i];
        for (auto &c:s[i]) {
            if (c == '#') {
                aru[i] = true;
                break;
            }
        }
    }
    for (int i=0; i<h; i++) {
        int init = cnt;
        for (int j=0; j<w; j++) {
            if (s[i][j] == '#')
                cnt++;
            if (aru[i])
                ans[i][j] = (cnt == init ? cnt + 1 : cnt);
            else if (i > 0)
                ans[i][j] = ans[i-1][j];
        }
    }
    if (!aru[0]) {
        int I=0;
        while (!aru[I]) I++;
        for (int i=I; i>0; i--)
            for (int j=0; j<w; j++) ans[i-1][j] = ans[i][j];
    }
    int off = ans[0][0] - 1;
    for (auto &ai:ans) {
        for (auto &aij:ai) {
            cout << aij - off << ' ';
        }
        cout << '\n';
    }
    return 0;
}