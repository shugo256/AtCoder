#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i=0, ai; i<m; i++) {
        cin >> ai;
        sum += ai;
    }
    cout << (sum <= n ? n - sum : -1) << '\n';
    return 0;
}