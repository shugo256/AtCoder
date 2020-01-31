#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    int sum = 0;
    for (int i=0, ai; i<n-1; i++) {
        cin >> ai;
        sum += ai;
    }
    cout << (n * m - sum <= k ? max(n * m - sum, 0) : -1) << '\n';
    return 0;
}