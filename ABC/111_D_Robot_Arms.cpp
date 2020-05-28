#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

using P = pair<ll, ll>;
#define fi first
#define se second

int main() {
    int n;
    cin >> n;
    P points[n];
    ll amari = -1;
    for (auto &pi:points) {
        cin >> pi.fi >> pi.se;
        if (amari < 0) {
            amari = abs(pi.fi + pi.se) % 2;
        } else if (amari != abs(pi.fi + pi.se) % 2) {
            cout << -1 << '\n';
            return 0;
        }
    }
    vector<ll> pow2{1ll};
    for (int i=amari; i<39; i++) {
        pow2.push_back(1ll << i);
    }
    cout << pow2.size() << '\n';
    for (auto &powi:pow2) cout << powi << ' ';
    cout << '\n';
    for (auto &pi:points) {
        string ans;
        ll x = pi.fi, y = pi.se;
        int i=0;
        if (amari == 0) {
            x++;
            i++;
            ans += 'L';
        }
        int tail_type;
        for (auto &powi:pow2) {
            if (powi >= max(abs(x), abs(y)) * 2) {
                if (abs(x) > abs(y)) {
                    if (x > 0) {
                        x -= powi;
                        tail_type = 0; // .., L, L, L, ..., L, R
                    } else {
                        x += powi;
                        tail_type = 1; // .., R, R, R, ..., R, L
                    }
                } else {
                    if (y > 0) {
                        y -= powi;
                        tail_type = 2; // .., D, D, .., U
                    } else {
                        y += powi;
                        tail_type = 3; // .., U, U, .., D
                    }
                }
                break;
            }
        }
        bool one_zero = (x == 0 || y == 0);
        for ( ; x != 0 || y != 0; i++) {
            if (one_zero) {
                if (x != 0) {
                    if (x == pow2[i]) {
                        x -= pow2[i];
                        ans += 'R';
                        continue;
                    } else if (x == -pow2[i]) {
                        x += pow2[i];
                        ans += 'L';
                        continue;
                    }
                } else {
                    if (y == pow2[i]) {
                        y -= pow2[i];
                        ans += 'U';
                        continue;
                    } else if (y == -pow2[i]) {
                        y += pow2[i];
                        ans += 'D';
                        continue;
                    }
                }
            }
            if (x % pow2[i+1]) {
                if ((bool)((x + pow2[i]) % pow2[i+2]) ^ (bool)(y % pow2[i+2])) {
                    x += pow2[i];
                    ans += 'L';
                } else {
                    x -= pow2[i];
                    ans += 'R';
                }
            } else if (y % pow2[i+1]) {
                if ((bool)((y + pow2[i]) % pow2[i+2]) ^ (bool)(x % pow2[i+2])) {
                    y += pow2[i];
                    ans += 'D';
                } else {
                    y -= pow2[i];
                    ans += 'U';
                }
            }
            one_zero = (x == 0 || y == 0);
        }
        string tail = "LRDU";
        for ( ; i<pow2.size()-1; i++) {
            ans += tail[tail_type];
        }
        ans += tail[tail_type ^ 1];
        cout << ans << '\n';
    }
    return 0;
}