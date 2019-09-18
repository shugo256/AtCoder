#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <list>

using ll = long long;

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int l = 0, r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        unordered_map<string, int> um;
        string sub = s.substr(0, m);
        // cerr << "Int" << sub << '\n';
        um[sub] = m;
        bool yes = false;
        for (int i=m+1; i<=n; i++) {
            sub += s[i-1];
            sub.erase(sub.begin());
            // cerr << sub << ' ' << um[sub] << ' ' << i << '\n';
            if (um[sub] > 0 && um[sub] + m <= i) {
                yes = true;
                //cerr << sub << '\n';
                break;
            }
            if (um[sub] == 0)
                um[sub] = i;
        }
        if (yes)
            l = m;
        else
            r = m;
    }
    cout << l << '\n';
    return 0;
}