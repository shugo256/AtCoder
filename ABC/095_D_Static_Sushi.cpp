#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long c;
    cin >> n >> c;
    long x[n], v[n], l[n+1], r[n+1], lb[n+1], rb[n+1];
    l[0] = 0; r[n] = 0; lb[0] = 0; rb[n] = 0;
    for (int i=0; i<n; i++)
        cin >> x[i] >> v[i];
    long suml=0, sumr=0;
    for (int i=0; i<n; i++) {
        suml += v[i];
        sumr += v[n-1-i];
        l[i+1]    = max(l[i],    suml - x[i]);
        lb[i+1]   = max(lb[i],   suml - x[i]*2);
        r[n-1-i]  = max(r[n-i],  sumr - (c - x[n-1-i]));
        rb[n-1-i] = max(rb[n-i], sumr - (c - x[n-1-i])*2);
    }
    long best=0;
    for (int i=0; i<=n; i++)
        best = max({best, l[i] + rb[i], r[i] + lb[i]});
    cout << best << '\n';
    return 0;
}