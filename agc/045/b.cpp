#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    int l = 0, r = 0, rui[n];
    for (int i=0; i<n; i++) {
        if (s[i] == '1') l++;
        else l--;
        if (s[i] == '0') r--;
        else r++;
        rui[i] = l;
    }
    int prev = 0;
    for (int i=n-1; i>=0; i--) {
        rui[i] = max(prev, rui[i]);
        prev = rui[i];
    }
    while ()
    return 0;
}