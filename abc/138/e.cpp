#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

// にぶたんVER

int main() {
    string s, t;
    cin >> s >> t;
    set<long> ids[26];
    long i=0, slen = s.size();
    for (auto c:s) {
        ids[c-'a'].insert(++i);
        ids[c-'a'].insert(i+slen);
    }
    long ans = 0, prev = 0;
    for (auto c:t) {
        if (ids[c-'a'].empty()) {
            cout << -1 << '\n';
            return 0;
        }
        long next = *ids[c-'a'].upper_bound(prev);
        if (next >= slen) ans += slen;
        prev = next % slen;
    }
    cout << ans + prev << '\n';
    return 0;
}