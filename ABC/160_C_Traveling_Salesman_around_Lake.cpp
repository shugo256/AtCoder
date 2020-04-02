#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    int dif = 0;
    int prev, first;
    cin >> prev;
    first = prev;
    for (int i=1, ai; i<n; i++) {
        cin >> ai;
        dif = max(dif, ai - prev);
        prev = ai;
    }
    cout << min(k - dif, prev - first) << '\n';
    return 0;
}