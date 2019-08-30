#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define long long long

using namespace std;

int main() {
    int n;
    cin >> n;
    long ans=0, best=1e17;
    for (int i=0; i<n; i++) {
        long a, b;
        cin >> a >> b;
        if (a > b) best = min(best, b);
        ans += a;
    }
    cout << max(ans - best, 0ll) << '\n';
    return 0;
}