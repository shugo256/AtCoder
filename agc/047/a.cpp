#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

int main() {
    int n;
    cin >> n;
    ll rui[100][100] = {{0}};
    P status[n];
    for (int i=0; i<n; i++) {
        string as; cin >> as;
        int d = 0;
        ll al = 0;
        bool after_dot = false;
        for (auto &asi:as) {
            if (asi == '.') after_dot = true;
            else {
                if (after_dot) d++;
                al *= 10;
                al += (asi - '0');
            }
        }
        // std::cerr << al << std::endl;
        int d2 = 0, d5 = 0;
        while (al % 2 == 0) {
            al /= 2;
            d2++;
        }
        while (al % 5 == 0) {
            al /= 5;
            d5++;
        }
        status[i] = {d2 - d, d5 - d};
        rui[d2 - d + 50][d5 - d + 50]++;
    }
    for (int i=0; i<100; i++) {
        for (int j=99; j>0; j--) {
            rui[i][j-1] += rui[i][j];
        }
    }
    for (int j=0; j<100; j++) {
        for (int i=99; i>0; i--) {
            rui[i-1][j] += rui[i][j];
        }
    }
    ll ans = 0;
    for (auto &si:status) {
        // cerr << si.fi << ' ' << si.se << ' ' << rui[-si.fi + 50][-si.se + 50] << '\n';
        ans += rui[-si.fi + 50][-si.se + 50];
        if (si.fi >= 0 && si.se >= 0) ans--;
    }
    cout << ans / 2 << '\n';
    return 0;
}