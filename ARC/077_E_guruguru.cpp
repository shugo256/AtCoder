#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    long n, m, p, a;
    cin >> n >> m >> p;
    long rui[2*m+1], sum = 0;
    fill(rui, rui+2*m+1, 0);
    for (long i=0; i<n-1; i++) {
        p %= m;
        cin >> a;
        if (a < p) a += m;
        sum += a - p;
        rui[p+1] += -1;
        rui[a]   += a - p;
        rui[a+1] += p - a + 1;
        p = a;
    }
    for (int i=1; i<=2*m; i++)
        rui[i] += rui[i-1];
    for (int i=1; i<=2*m; i++)
        rui[i] += rui[i-1];
    long dif = 0;
    for (int i=1; i<=m; i++)
        dif = min(dif, rui[i] + rui[i+m]);
    cout << dif + sum << '\n';
    return 0;
}