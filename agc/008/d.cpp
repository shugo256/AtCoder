#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <numeric>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    int x[n];
    for (auto &xi:x) cin >> xi;
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int l, int r) {
        return x[l] < x[r];
    });
    queue<int> q;
    for (auto id:ids)
        for (int k=0; k<id; k++) 
            q.push(id);
    int i=0, cnt[n];
    fill(cnt, cnt+n, 0);
    vector<int> ans;
    while (!q.empty() || i < n && ans.size() == x[ids[i]] - 1) {
        int a;
        if (i < n && ans.size() == x[ids[i]] - 1) {
            a = ids[i];
            if (cnt[a] != a) break;
            for (int k=ids[i]+1; k<n; k++) q.push(ids[i]);
            i++;
        } else {
            a = q.front(); 
            q.pop();
        }
        ans.push_back(a+1);
        cnt[a]++;
    }
    if (ans.size() < n*n) {
        cout << "No" << '\n';
        return 0;
    }
    cout << "Yes" << '\n';
    for (int i=0; i<n*n; i++) cout << ans[i] << (i < n*n-1 ? ' ' : '\n');
    return 0;
}