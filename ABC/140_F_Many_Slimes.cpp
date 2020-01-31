#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int, greater<int> > cnt;
    for (int i=0; i<(1<<n); i++) {
        int s; cin >> s;
        cnt[s]++;
    }
    int slots[n+1];
    fill(slots, slots+n+1, 0);
    slots[0] = 1;
    for (auto &c:cnt) {
        int ci = c.second;
        int buf[n+1];
        fill(buf, buf + n+1, 0);
        for (int i=0; i<=n; i++) {
            int dif = min(slots[i], ci);
            slots[i] -= dif;
            ci -= dif;
            for (int j=i+1; j<=n; j++)
                buf[j] += dif;
            if (ci == 0) break;
        }
        if (ci > 0) {
            cout << "No\n";
            return 0;
        }
        for (int i=0; i<=n; i++) slots[i] += buf[i];
    }
    cout << "Yes" << '\n';
    return 0;
}