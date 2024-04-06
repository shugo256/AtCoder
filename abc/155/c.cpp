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
    map<string, int> m;
    int best = 0;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        m[s]++;
        best = max(best, m[s]);
    }
    for (auto &p:m)
        if (p.second == best) cout << p.first << '\n';
    return 0;
}