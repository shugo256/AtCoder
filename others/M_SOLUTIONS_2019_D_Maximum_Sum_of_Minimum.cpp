#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef pair<int,int> P;

int main() {
    int n;
    cin >> n;
    vector<int> G[n];
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int c[n];
    for (auto &ci:c) cin >> ci;
    sort(c, c+n);
    int len[n], d[n], m=0, ucnt=0;
    bool used[10000] = {0};
    for (int i=0; i<n; i++) len[i] = (int)G[i].size();
    while (ucnt < n) {
        // for (auto l : len) cerr << l << '\n';
        for (int i = 0; i < n; i++) {
            if (used[i] || len[i] > 1) continue;
            if (!used[i] && len[i] == 0) {
                d[i] = c[ucnt];
                ucnt = n; break;
            }
            d[i] = c[ucnt];
            m += c[ucnt];
            ucnt++;
            len[i] = 0;
            for (auto g:G[i])
                if (!used[g])
                    len[g]--;
            used[i] = true;
        }
    }
    cout << m << '\n';
    for (int i=0; i<n; i++) 
        cout << d[i] << (i==n-1 ? '\n' : ' ');
    return 0;
}
