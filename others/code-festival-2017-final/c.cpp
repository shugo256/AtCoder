#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int d[n];
    for (auto &di:d) cin >> di;
    sort(d, d+n);
    int best = d[0];
    if (n > 1)
        best = min(best, 24 - d[n-2]-d[n-1]);
    if (n > 2)
        for (int i=0; i<n-2; i++)
            best = min(best, d[i+2] - d[i]);
    cout << best << '\n';
    return 0;
}