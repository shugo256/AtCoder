#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i=0; i<n; i++) {
        string s; int t;
        cin >> s >> t;
        for (auto &m:mp) m.second += t;
        mp[s] = 0;
    }
    string x; cin >> x;
    cout << mp[x] << '\n';
    return 0;
}