#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <deque>

using ll = long long;

using namespace std;

int main() {
    string s;
    int q, rev = 0;
    cin >> s >> q;
    deque<char> dq(s.begin(), s.end());
    for (int i=0; i<q; i++) {
        int t; cin >> t;
        if (t == 1) rev ^= 1;
        else {
            int f; char c;
            cin >> f >> c;
            if (rev == f-1) dq.push_front(c);
            else dq.push_back(c);
        }
    }
    cout << (rev ? string(dq.rbegin(), dq.rend()) : string(dq.begin(), dq.end())) << '\n';
    return 0;
}