#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>

using ll = long long;

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    ll cnt = 0;
    for (int i=1; 2*i<n; i++) {
        for (int j=0; j+2*i<n; j++) {
            set<char> st{s[j], s[j+i], s[j+2*i]};
            if (st.size() == 3) {
                cnt++;
            }
        }
    }
    map<char, ll> m;
    for (auto &c:s) m[c]++;
    cout << m['R'] * m['G'] * m['B'] - cnt << '\n';
    return 0;
}