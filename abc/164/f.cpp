#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>
#include <set>

using ull = unsigned long long;

using namespace std;

using BS = bitset<64>;

int main() {
    int n;
    cin >> n;
    ull a[n][n];
    fill(a[0], a[n], 0ull);
    bool S[n], T[n];
    BS U[n], V[n];
    for (auto &si:S) cin >> si;
    for (auto &si:T) cin >> si;
    for (auto &si:U) {
        ull ui;
        si = ui;
    }
    for (auto &si:V) {
        ull vi;
        cin >> vi;
        si = vi;
    }
    bool used[n][n];
    for (int d=0; d<64; d++) {
        int allr = -1, allc = -1;
        vector<int> row[2], col[2];
        set<
        fill(used[0], used[n], false);
        for (int i=0; i<n; i++) {
            if (S[i] ^ U[i][d]) {
                for (int j=0; j<n; j++) {
                    a[i][j] |= (1ull << d) * U[i][d];
                    used[i][j] = true;
                    if (allr < 0) allr = U[i][d];
                    else if (allr != U[i][d]) {
                        cout << -1 << '\n';
                        return 0;
                    }
                }
            } else {
                row[U[i][d]].push_back(i);
            }
            if (T[i] ^ V[i][d]) {
                for (int j=0; j<n; j++) {
                    a[i][j] |= (1ull << d) * T[i][d];
                    if (allc < 0) allc = V[i][d];
                    else if (allc != V[i][d]) {
                        cout << -1 << '\n';
                        return 0;
                    }
                    if (allc >= 0 && allr >= 0 && allc != allr) {
                        cout << -1 << '\n';
                        return 0;
                    }
                }
            } else {
                col[U[i][d]].push_back(i);
            }
        }
        int id = 0;
        for (int b=0; b<2; b++) {
            for (auto &ri:row[b]) {
                
            }
        }

    }
    cout << n << '\n';
    return 0;
}