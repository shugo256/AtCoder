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
    map<string, int> cnt;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        cnt[s]++;
    }
    for (auto &s:{"AC", "WA", "TLE", "RE"}) {
        cout << s << " x " << cnt[string(s)] << '\n';
    }
    return 0;
}