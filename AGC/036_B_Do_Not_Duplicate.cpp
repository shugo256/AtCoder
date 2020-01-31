#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    long n, k;
    cin >> n >> k;
    int a[n], last[200001], next[n];
    fill(last, last+200001, -1);
    fill(next, next+n, 2000000);
    for (auto &ai:a) cin >> ai;
    for (int i=0; i<2*n; i++) {
        int ai = a[i % n];
        if (0 <= last[ai] && last[ai] < n && next[last[ai]] > i) next[last[ai]] = i + 1;
        last[ai] = i;
    }
    int cur = 0;
    long cnt = 0;
    vector<long> starts;
    do {
        starts.push_back(cnt);
        cnt += next[cur] - cur;
        cur = next[cur] % n;
    } while (cur > 0);
    auto st = prev(upper_bound(starts.begin(), starts.end(), (n * k) % cnt));
    for (int i=(*st % n); i<n; ) {
        if (next[i] <= n) {
            i = next[i];
            continue;
        }
        cout << a[i] << ' ';
        i++;
    }
    cout << endl;
    return 0;
}