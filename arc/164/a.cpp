#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

bool isTrinaryComposable(ll n, ll k) {
  while (n > 0) {
    k -= n % 3;
    n /= 3;
  }
  return k >= 0 && k % 2 == 0;
}

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    ll n, k;
    std::cin >> n >> k;
    std::cout << (isTrinaryComposable(n, k) ? "Yes" : "No") << '\n';
  }
  return 0;
}