#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    ll rui[n+1];
    rui[0] = 0;
    for (int i=0; i<n; i++) {
        ll ai;
        cin >> ai;
        rui[i+1] = rui[i] + ai;
    }
    int h = lower_bound(rui, rui+n+1, rui[n] / 2) - rui;
    cout << min(abs(rui[n] - rui[h]*2), abs(rui[n] - rui[h-1]*2)) << '\n';
    return 0;
}