#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

int main() {
    int n; string t;
    cin >> n >> t;
    int pow3[n+1];
    pow3[0] = 1;
    for (int i=1; i<=n; i++) pow3[i] = pow3[i-1] * 3;
    int dance[pow3[n]], d = 1;
    for (int i=0; i<pow3[n]; i++) {
        dance[i] = i / d;
        if (d * 3 <= i + 1) d *= 3;
    }
    vector<int> applied(pow3[n], 0);
    int cnt = 0;
    for (auto &c:t) {
        if (c == 'S') {
            cnt++;
        } else {
            int sum = 0;
            dance[0] ^= ((cnt - applied[0]) & 1) * 3; dance[0] = (dance[0] + 1) % 3;
            applied[0] = cnt;
            for (int i=0; i<n; i++) {
                int x1 = sum + pow3[i];
                int x2 = sum + pow3[i] * 2;
                dance[x1] ^= ((cnt - applied[x1]) & 1) * 3; dance[x1] = (dance[x1] + 1) % 3;
                dance[x2] ^= ((cnt - applied[x1]) & 1) * 3; dance[x2] = (dance[x2] + 1) % 3;
                applied[x1] = applied[x2] = cnt;
                if (dance[x1] == 0)
                    sum = x1;
                else if (dance[x2] == 0) 
                    sum = x2;
            }
        }
    }
    d = 3;
    for (auto &di:dance) cerr << di << ' ';
    cerr << '\n';
    for (int i=0; i<pow3[n]; i++) {
        dance[i] ^= ((cnt - applied[i]) & 1) * 3;
        dance[i] = dance[i % d] + dance[i] * d;
        if (i + 1 >= d * 3) d *= 3;
        left.insert(i);
    }
    for (auto &di:dance) cerr << di << ' ';
    cerr << '\n';
    for (int i=pow3[n]-1; i>=0; i--) {
        if (left.count(dance[i]) == 0) {
            for (int di = d; d <= n; di++) {
                if (left.count(dance[i] + d)) {
                    dance[i] += d;

                }
                else if (left.count(dance[i] + 2*d)) dance[i] += 2*d;
            }
        }
        left.erase(dance[i]);
        if (i * 3 == d) d /= 3;
    }
    for (auto &di:dance) cout << di << ' ';
    cout << '\n';
    return 0;
}