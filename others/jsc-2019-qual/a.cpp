#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

#define long long long

using namespace std;

int main() {
    int m, d;
    cin >> m >> d;
    int cnt=0;
    for (int i=4; i<=m; i++) {
        int r = sqrt(m);
        for (int j=2; j<=r; j++) {
            if (i / j >= 10 || i % j != 0) continue;
            int d10 = j, d1 = i / j;
            if (d10 > d1) break;
            if (d1 + d10 * 10 <= d)
                cnt++;
            else 
                break;
            if (d1 != d10 && d1 * 10 + d10 <= d) cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}