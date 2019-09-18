#include <iostream>
#include <algorithm>

using namespace std;

#define mining(a, b) a = min(a, b)

int main() {
    int n;
    long x;
    cin >> n >> x;
    long a[n], mins[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
        mins[i] = 1000000000000000;
    }
    long ans = 1000000000000000;
    for (int k=0; k<n; k++) {
        long sum = x * k;
        for (int i=k; i<n+k; i++) {
            mining(mins[i%n], a[i-k]);
            sum += mins[i%n];
        }
        mining(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}