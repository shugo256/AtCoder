#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    bool sym = true;
    for (int i=0; i<n/2; i++) 
        if (s[i] != s[n-2-i]) {
            sym = false;
            break;
        }
    if (s[0] == '0' || s[n-1] == '1' || !sym) {
        cout << -1 << '\n';
        return 0;
    }
    int now = 1;
    for (int i=2; i<=n; i++) {
        cout << now << ' ' << i << '\n';
        if (i - 2 < n / 2 && s[i-2] == '1') now = i;
    }
    return 0;
}