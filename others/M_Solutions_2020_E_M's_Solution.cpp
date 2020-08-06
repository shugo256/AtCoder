#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <bitset>

using ll = long long;

using namespace std;

struct city {
    ll x, y, p;
}

int main() {
    int n;
    cin >> n;
    vector<city> cities(n);
    vector<ll> ans(n+1);
    ll s0 = 0;
    for (auto &ci:cities) {
        cin >> ci.x >> ci.y >> ci.p;
        s0 += min(abs(ci.x), abs(ci.y)) * ci.p;
    }
    fill(ans.begin(), ans.end(), s0);
    for (int i=1; i<(1 << n); i++) {
        int c = bitset<15>(i).count();
        for (int j=0; j<(1 << c); j++) {
            vector<city> x, y, left;
            int jd = 0;
            for (int k=0; k<n; k++) {
                if ((i >> k) & 1 == 0) {
                    left.push_back(cities[k]);
                } else {
                    if ((j >> jd) & 1) {
                        x.push_back(cities[k]);
                    } else {
                        y.push_back(cities[k]);
                    }
                    jd++;
                }
            }
        }
    }
    return 0;
}