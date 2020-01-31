#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int x = a ^ b;
    vector<int> even, palette;
    int prev = -1;
    for (int i=0; i<n; i++) {
        int d = 1 << i;
        if (x & d) 
            if (prev < 0) prev = d;
            else {
                palette.push_back(prev);
                palette.push_back(d);
                palette.push_back(d);
                palette.push_back(prev);
                prev = -1;
            }
        else
            even.push_back(d);
    }
    if (prev < 0) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    for (auto &e:even) {
        palette.push_back(e);
        palette.push_back(e);
    }
    palette.push_back(prev);
    for (auto p: palette) cerr << p << '\n';
    int len = (1 << n), p = a;
    cout << p << ' ';
    int board[n];
    for (int i=0; i<n; i++) board[i] = 1 << ((i / 2 + 1) * 2);
    for (int i=1; i<len; i++) {
        int d = i & -i,
            log = 0;
        while (!(d & (1 << log))) log++;
        // cerr << 2*log + (i > board[log]) << '\n';
        p ^= palette[2*log + (i > board[log])];
        cout << p << ' ';
    }
    cout << '\n';
    return 0;
}