#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    ll a[n]; for (auto &ai:a) cin >> ai;
    for (int i=0; i<n-k; i++) {
        cout << (a[i] < a[i+k] ? "Yes" : "No") << '\n';
    }
    return 0;
}