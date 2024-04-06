#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n-1], b[n-1], a0, b0;
    cin >> a0 >> b0;
    for (int i=0; i<n-1; i++)
        cin >> a[i] >> b[i];
    vector<int> d;
    int root = (int)sqrt(max(a0,b0));
    for (int i=root; i>=1; i--) {
        if (a0 % i != 0 && b0 % i != 0) continue;
        d.push_back(i);
        if (a0 % i == 0) d.push_back(a0 / i);
        if (b0 % i == 0 && a0 != b0) d.push_back(b0 / i);
    }
    sort(d.begin(), d.end(), greater<int>());
    for (auto i:d) {
        int j = 0;
        for ( ; j<n-1; j++) {
            if (a[j] % i != 0 && b[j] % i != 0)
                break;
        }
        if (j == n-1) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
