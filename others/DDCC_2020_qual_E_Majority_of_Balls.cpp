#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    string t;
    cout << "?";
    for (int i=1; i<=n; i++) cout << ' ' << i;
    cout << endl;
    cin >> t;
    char f = t[0];
    int l = 1, r = n+1, m;
    while (r - l > 1) {
        m = (l + r) / 2;
        cout << "?";
        for (int i=m; i<m+n; i++) cout << ' ' << i;
        cout << endl;
        cin >> t;
        if (t[0] == f) l = m;
        else r = m;
    }
    string ans = "";
    for (int i=1; i<=2*n; i++) {
        cout << "? " << i;
        if (i < m || i >= l+n-1)
            for (int j=l; j<l+n-1; j++) cout << ' ' << j;
        else  {
            for (int j=1; j<=2*n; j++)
                if (j < l-1 || j >= l+n)
                    cout << ' ' << j;
        }
        cout << endl;
        cin >> t;
        ans += t[0];
    }
    cout << "! " +  ans << endl;
    return 0;
}
