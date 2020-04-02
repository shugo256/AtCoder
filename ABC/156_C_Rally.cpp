#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define INF 1000000

int main() {
    int n;
    cin >> n;
    int x[n];
    for (auto &xi:x) cin >> xi;
    int ans = INF;
    for (int p = 1; p <= 100; p++) {
        int sum = 0;
        for (auto &xi:x) sum += (xi - p) * (xi - p);
        ans = min(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}