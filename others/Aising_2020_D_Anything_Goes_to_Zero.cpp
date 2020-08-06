#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>

using ll = long long;

using namespace std;

#define MAX 200010

#define popcount(x) (int)bitset<32>(x).count()

int main() {
    int n;
    cin >> n;
    int f[MAX];
    f[0] = 0;
    for (int i=1; i<MAX; i++) {
        f[i] = f[i % popcount(i)] + 1;
    }
    string x; cin >> x;
    int pc = 0;
    for (auto &c:x) {
        if (c == '1') pc++;
    }
    // cerr << bitset<32>(x).to_ulong() << ' ' << pc << ' ' << bitset<32>(x).to_ulong() % (pc + 1) << ' ' << bitset<32>(x).to_ulong() % (pc - 1) << '\n';
    int up[n], down[n], upr = 0, downr = 0;
    up[n-1] = down[n-1] = 1;
    for (int i=n-1; i>0; i--) {
        up[i-1]   = (up[i] * 2) % (pc + 1);
        if (pc > 1) {
            down[i-1] = (down[i] * 2) % (pc - 1);
        }
    }
    for (int i=n-1; i>=0; i--) {
        if (x[i] == '1') {
            upr = (upr + up[i]) % (pc + 1);
            if (pc > 1) downr = (downr + down[i]) % (pc - 1);
        }
    }
        // cerr << upr << ' ' << downr << '\n';
    for (int i=0; i<n; i++) {
        // cerr << up[i] << ' ' << down[i] << '\n';
        if (x[i] == '0') {
            cout << f[(upr + up[i]) % (pc + 1)] + 1 << '\n';
        }
        else if (pc > 1) {
            cout << f[(downr - down[i] + pc - 1) % (pc - 1)] + 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}