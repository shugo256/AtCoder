#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

struct query {
    int a, b, c, d;
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    query qs[q];
    for (int i=0, ai, b, c, d; i<q; i++) {
        cin >> ai >> b >> c >> d;
        ai--; b--;
        qs[i] = {ai, b, c, d};
    }
    int a[10];
    int ans = 0;
    int x = 0;
    for (a[0]=1;    a[0]<=m; a[0]++) 
    for (a[1]=a[0]; a[1]<=m; a[1]++)
    for (a[2]=a[1]; a[2]<=m; a[2]++) 
    for (a[3]=a[2]; a[3]<=m; a[3]++) 
    for (a[4]=a[3]; a[4]<=m; a[4]++) 
    for (a[5]=a[4]; a[5]<=m; a[5]++) 
    for (a[6]=a[5]; a[6]<=m; a[6]++) 
    for (a[7]=a[6]; a[7]<=m; a[7]++) 
    for (a[8]=a[7]; a[8]<=m; a[8]++) 
    for (a[9]=a[8]; a[9]<=m; a[9]++) {
        int cnt = 0;
        x++;
        for (auto &qi:qs) {
            if (a[qi.b] - a[qi.a] == qi.c) {
                cnt += qi.d;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    cerr << x << '\n';
    return 0;
}