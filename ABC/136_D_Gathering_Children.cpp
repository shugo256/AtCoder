#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int lc = 0, rc = 0, i = 0, tani;
    int n = s.size();
    int res[n];
    fill(res, res+n, 0);
    for (auto c:s) {
        if (c == 'L' && lc > 0) {
            if (rc == 0) tani = i;
            rc++;
        }
        else if (c == 'R') {
            if (rc > 0 && lc > 0) {
                res[tani]   = lc / 2 + (rc + 1) / 2;
                res[tani-1] = rc / 2 + (lc + 1) / 2;
                lc = 0;
                rc = 0;
            }
            lc++;
        }
        i++;
    }
    if (rc > 0 && lc > 0) {
        res[tani]   = lc / 2 + (rc + 1) / 2;
        res[tani-1] = rc / 2 + (lc + 1) / 2;
        rc = 0;
    }
    for (int i=0; i<n; i++) cout << res[i] << (i < n-1 ? ' ' : '\n');
    return 0;
}