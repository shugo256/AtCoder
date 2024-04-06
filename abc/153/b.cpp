#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int h, n;
    cin >> h >> n;
    for (int i=0, ai; i<n; i++) {
        cin >> ai;
        h -= ai;
    }
    cout << (h <= 0 ? "Yes" : "No") << '\n';
    return 0;
}