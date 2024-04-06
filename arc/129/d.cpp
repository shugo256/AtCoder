#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <numeric>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
    ll sum = 0, cumulativeSum = 0;
    for (auto &ai : a) {
        std::cin >> ai;
        sum += ai;
        cumulativeSum += sum;
    }
    
    ll ans = -1;
    if (sum == 0 && cumulativeSum % n == 0) {
        std::vector<ll> x(n, 0);
        x[n-1] = cumulativeSum / n;
        for (int i = 1; i < n - 1; i++) {
            x[i] = a[i-1] - x[(i - 2 + n) % n] + x[i - 1] * 2;
        }

        ll min = *std::min_element(x.begin(), x.end());
        ans = std::accumulate(x.begin(), x.end(), 0ll) - min * n;
    }
    
    std::cout << ans << '\n';
    return 0;
}