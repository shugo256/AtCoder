#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <queue>

using ll = long long;

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    queue<int> a[n];
    for (int i=0; i<n; i++) for (int j=0, aij; j<m; j++) {
        cin >> aij;
        a[i].push(aij - 1);
    }
    int cnt[m];
    vector<bool> used(m, false);
    int ans = n;
    for (int j=0; j<m; j++) {
        fill(cnt, cnt+m, 0);
        int best = -1;
        for (auto &ai:a) {
            while (used[ai.front()]) ai.pop();
            cnt[ai.front()]++;
            if (best < 0 || cnt[best] < cnt[ai.front()]) {
                best = ai.front();
            }
        }
        ans = min(ans, cnt[best]);
        used[best] = true;
    }
    cout << ans << '\n';
    return 0;
}