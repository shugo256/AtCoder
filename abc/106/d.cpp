#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    int rui[510][510] = {{0}};
    for (int i=0; i<m; i++) {
        int li, ri;
        cin >> li >> ri;
        rui[li][ri]++;
    }
    for (int l=n; l>0; l--)
        for (int r=l; r<=n; r++)
            rui[l][r] += rui[l+1][r] + rui[l][r-1] - rui[l+1][r-1];
    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        cout << rui[a][b] << '\n';
    }
    return 0;
}