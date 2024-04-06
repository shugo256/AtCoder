#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
    for (auto &ai:a) std::cin >> ai;
    std::sort(a.begin(), a.end());
    ll sum = 0, ans = 0;
    for (int i=0; i<n; i++) {
        ans += a[i] * i - sum;
        sum += a[i];
    }
    std::cout << ans << '\n';
    return 0;
}