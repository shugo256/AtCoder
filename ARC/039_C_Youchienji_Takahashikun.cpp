#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

struct cell {
    int l, r, d, u;
    int &operator[](char c) {
        switch (c) {
            case 'L': return l;
            case 'R': return r;
            case 'U': return u;
            case 'D': return d;
            default: return l;
        }
    }
};

map<char, char> opp {
    {'U', 'D'},
    {'D', 'U'},
    {'L', 'R'},
    {'R', 'L'}
};

int main() {
    int k;
    string s;
    cin >> k >> s;
    P tak = {0, 0};
    map<P, cell> mp;
    const string directions = "UDLR";
    for (auto &c:s) {
        if (!mp.count(tak)) mp[tak] = {tak.fi-1, tak.fi+1, tak.se-1, tak.se+1};
        for (auto &d:directions) {
            P nei = ((d == 'U' || d == 'D') ? P{tak.fi, mp[tak][d]} : P{mp[tak][d], tak.se});
            if (!mp.count(nei)) {
                mp[nei] = {nei.fi-1, nei.fi+1, nei.se-1, nei.se+1};
            }
            mp[nei][opp[d]] = mp[tak][opp[d]];
        }
        if (c == 'L' || c == 'R')
            tak.fi = mp[tak][c];
        else
            tak.se = mp[tak][c];
    }
    cout << tak.fi << ' ' << tak.se << '\n';
    return 0;
}