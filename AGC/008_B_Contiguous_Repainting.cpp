#include <iostream>
#include <algorithm>

using namespace std;

#define relu(x) max(x, 0l)

int main() {
    int n, k;
    cin >> n >> k;
    long a[n], rui[n+1], top[n+1];
    for (auto &ai:a) cin >> ai;
    rui[0] = top[0] = 0;
    for (int i=0; i<n; i++) {
        rui[i+1] = rui[i] + a[i];
        top[i+1] = top[i] + relu(a[i]);
    }
    long ans = 0;
    for (int i=0; i<=n-k; i++)
        ans = max(ans, top[n] - top[i+k] + relu(rui[i+k] - rui[i]) + top[i]);
    cout << ans << '\n';
    return 0;
}