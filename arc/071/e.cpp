#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int slen = s.size(), tlen = t.size(),
        ruis[slen+1], ruit[tlen+1];
    ruis[0] = ruit[0] = 0;
    for (int i=0; i<slen; i++) {
        if (s[i] == 'A') ruis[i+1] = ruis[i] + 1;
        else ruis[i+1] = ruis[i] - 1;
    }
    for (int i=0; i<tlen; i++) {
        if (t[i] == 'A') ruit[i+1] = ruit[i] + 1;
        else ruit[i+1] = ruit[i] - 1;
    }
    int q, a, b, c, d; cin >> q;
    while (q--) {
        cin >> a >> b >> c >> d;
        int sdif = ruis[b] - ruis[a-1],
            tdif = ruit[d] - ruit[c-1];
        cout << (abs(sdif - tdif) % 3 == 0 ? "YES" : "NO") << '\n';
    }
    return 0;
}