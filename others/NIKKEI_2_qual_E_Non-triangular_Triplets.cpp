#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

struct T{long a, b, c;};

int main() {
    long n, k;
    cin >> n >> k;
    if (n < 2 * k + 3) {
        cout << -1 << '\n';
        return 0;
    }
    vector<T> ans;
    long x = k + n * 3 - 1, y = k + n * 2, z = x - y,
        x2 = x-1, y2 = 2*k + n - 1, z2 = n+1;
    bool done = false;
    for (int i=0; i<n; i++) {
        if (i % 2 || done) {
            ans.push_back(T{z, y, x});
            x -= 2; y--; z--;
        }
        else {
            if (y2 + z2 > x2) {
                cout << -1 << '\n';
                return 0;
            }
            ans.push_back(T{z2, y2, x2});
            x2 -= 2;
            y2--; z2++;
            if (y2 <= z2) done = true;
        }
    }
    for (auto &t:ans) cout << t.a << ' ' << t.b << ' ' << t.c << '\n';
    cout << n << '\n';
    return 0;
}