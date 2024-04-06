#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    int cnt[3][30] = {{0}},
        d[c][c];
    for (auto &di:d)
        for (auto &dij:di)
            cin >> dij;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int cij; cin >> cij;
            cnt[(i+j)%3][cij-1]++;
        }
    }
    int sc[3], best = 250000001;
    for (sc[0]=0; sc[0]<c; sc[0]++) {
        for (sc[1]=0; sc[1]<c; sc[1]++) {
            if (sc[0] == sc[1]) continue;
            for (sc[2]=0; sc[2]<c; sc[2]++) {
                if (sc[2] == sc[0] || sc[2] == sc[1]) continue;
                int sum = 0;
                for (int i=0; i<3; i++)
                    for (int j=0; j<c; j++)
                        sum += d[j][sc[i]] * cnt[i][j];
                best = min(best, sum);
                //cerr << sc[0] << ' ' << sc[1] << ' ' << sc[2] << ' ' << sum << '\n';
            }
        }
    }
    cout << best << '\n';
    return 0;
}