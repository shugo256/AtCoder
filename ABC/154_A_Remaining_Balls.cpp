#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

int main() {
    string s, t, u;
    map<string, int> mp;
    cin >> s >> t;
    cin >> mp[s] >> mp[t] >> u;
    mp[u]--;
    cout << mp[s] << ' ' << mp[t] << '\n';
    return 0;
}